#include "newgamepanel.h"

using namespace mtg::gui;

NewGamePanel::NewGamePanel()
{
    shadower.setOwner (this);

    closeButton.onClick = [this] { close(); };
    addAndMakeVisible(closeButton);

    gameModeClassicButton.onClick = []{};
    addAndMakeVisible(gameModeClassicButton);

    gameModeEdhButton.onClick = []{};
    addAndMakeVisible(gameModeEdhButton);
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

    gameModeClassicButton.setBounds(getLocalBounds().withSizeKeepingCentre(140, 40).translated(80, 0));
    gameModeEdhButton.setBounds(gameModeClassicButton.getBoundsInParent().translated(-160, 0));
    /*
    auto bounds = getLocalBounds();
    instructions.setBounds (bounds.removeFromBottom (30));

    FlexBox flexBox;
    flexBox.flexDirection = FlexBox::Direction::row;
    flexBox.flexWrap = FlexBox::Wrap::noWrap;
    flexBox.justifyContent = FlexBox::JustifyContent::center;
    flexBox.alignItems = FlexBox::AlignItems::center;

    const auto height = (float) (bounds.getHeight() - 2 * margin);

    flexBox.items.add (FlexItem (label).withWidth (200.0f).withHeight (height));

    for (auto& c : toolComponents)
        flexBox.items.add (FlexItem (*c).withWidth (height).withHeight (height).withMargin (margin));

    flexBox.performLayout (bounds);
    */
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
