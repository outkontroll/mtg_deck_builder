#include "newgamepanel.h"

using namespace mtg::gui;

namespace {

constexpr auto margin = 15;
constexpr auto groupIdGameMode = 1;

}

NewGamePanel::NewGamePanel()
{
    shadower.setOwner (this);

    closeButton.onClick = [this] { close(); };
    addAndMakeVisible(closeButton);

    startGameButton.onClick = [this] { startGame(); };
    addAndMakeVisible(startGameButton);

    gameModeClassicButton.onClick = [this]{ updateGameModeSelection(gameModeClassicButton); };
    addAndMakeVisible(gameModeClassicButton);

    gameModeCommanderButton.onClick = [this]{ updateGameModeSelection(gameModeCommanderButton); };
    addAndMakeVisible(gameModeCommanderButton);

    gameModeCommanderButton.setRadioGroupId(groupIdGameMode);
    gameModeClassicButton.setRadioGroupId(groupIdGameMode);

    gameModeClassicButton.setToggleState(true, juce::NotificationType::sendNotification);

    //addChildComponent (setupComponent, 0);
}

void NewGamePanel::paint(juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId).brighter (0.1f));
}

void NewGamePanel::resized()
{
    closeButton.setBounds (getLocalBounds().removeFromTop (40)
                              .removeFromRight (40)
                              .reduced (5));

    startGameButton.setBounds(getLocalBounds().removeFromBottom(40)
                              .removeFromRight(140)
                              .reduced(5));

    gameModeClassicButton.setBounds(getLocalBounds().withSizeKeepingCentre(170, 40).translated(95, 0));
    gameModeCommanderButton.setBounds(gameModeClassicButton.getBoundsInParent().translated(-170, 0));
}

void NewGamePanel::open()
{
    shouldOpen = true;
    updater.addAnimator (slideInAnimator, [this] { updater.removeAnimator (slideInAnimator); });
    slideInAnimator.start();
}

void NewGamePanel::close()
{
    shouldOpen = false;
    updater.addAnimator (slideInAnimator, [this]
                        {
                            juce::NullCheckedInvocation::invoke (onClose);
                            updater.removeAnimator (slideInAnimator);
                        });
    slideInAnimator.start();
}

void NewGamePanel::startGame()
{
    shouldOpen = false;
    updater.addAnimator (slideInAnimator, [this]
                        {
                            juce::NullCheckedInvocation::invoke (onStartGame);
                            updater.removeAnimator (slideInAnimator);
                        });
    slideInAnimator.start();
}

void NewGamePanel::updateGameModeSelection(juce::ToggleButton& button)
{
    auto state = button.getToggleState();
    if(state && &button == &gameModeClassicButton)
    {
        showClassicDecks();
    }
    else if(state && &button == &gameModeCommanderButton)
    {
        showCommanderDecks();
    }
}

void NewGamePanel::showClassicDecks()
{
    std::cout << "Classic decks" << "\n";
}

void NewGamePanel::showCommanderDecks()
{
    std::cout << "Commander decks" << std::endl;
}

auto NewGamePanel::createSlideInAnimator() -> juce::Animator
{
    return juce::ValueAnimatorBuilder{}
        .withEasing (juce::Easings::createEaseInOutCubic())
        .withOnStartReturningValueChangedCallback (
            [this]
            {
                const auto width = getParentWidth() - 2 * margin;
                const auto height = getParentHeight() - 2 * margin;
                setBounds (-width, margin, width, height);
                setVisible (true);

                const auto limits = juce::makeAnimationLimits (-width, margin);

                return [this, limits] (auto value)
                {
                    const auto progress = std::clamp (shouldOpen ? value : 1.0 - value, 0.0, 1.0);
                    setTopLeftPosition (juce::roundToInt (limits.lerp ((float) progress)), margin);
                };
            })
        .withDurationMs (500)
        .build();
}
