#include "newgamepanel.h"

using namespace mtg::gui;

namespace {
constexpr auto margin = 15;
}

NewGamePanel::NewGamePanel()
{
    shadower.setOwner (this);

    closeButton.onClick = [this] { close(); };
    addAndMakeVisible(closeButton);

    startGameButton.onClick = [this] { startGame(); };
    addAndMakeVisible(startGameButton);

    gameModeClassicButton.onClick = []{};
    addAndMakeVisible(gameModeClassicButton);

    gameModeCommanderButton.onClick = []{};
    addAndMakeVisible(gameModeCommanderButton);

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

    gameModeClassicButton.setBounds(getLocalBounds().withSizeKeepingCentre(140, 40).translated(80, 0));
    gameModeCommanderButton.setBounds(gameModeClassicButton.getBoundsInParent().translated(-160, 0));
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
