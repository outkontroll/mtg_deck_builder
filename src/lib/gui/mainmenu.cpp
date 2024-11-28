#include "mainmenu.h"

using namespace mtg::gui;

MainMenu::MainMenu()
{
    newGameButton.onClick = [this]
    {
        animateForward = true;
        buttonAnimator.start();
        updater.addAnimator (buttonAnimator, [this] { updater.removeAnimator (buttonAnimator); });
    };

    addAndMakeVisible (newGameButton);
}

void MainMenu::setOnAnimatedClickEnd(std::function<void ()> onClickIn)
{
    onClick = std::move (onClickIn);
}

void MainMenu::reset()
{
    animateForward = false;
    buttonAnimator.start();
    updater.addAnimator (buttonAnimator, [this] { updater.removeAnimator (buttonAnimator); });
}

void MainMenu::resized()
{
    newGameButton.setBounds (getLocalBounds().withSizeKeepingCentre (140, 40));
}

juce::Animator MainMenu::createButtonAnimator()
{
    return juce::ValueAnimatorBuilder{}
        .withOnStartCallback ([this] { setVisible (true); })
        .withValueChangedCallback ([this] (auto value) {
            const auto progress = animateForward ? value : (1.0 - value);
            setAlpha (1.0f - (float) progress);
        })
        .withOnCompleteCallback ([this]{
            setVisible (! animateForward);

            if (animateForward)
                juce::NullCheckedInvocation::invoke (onClick);
        })
        .build();
}
