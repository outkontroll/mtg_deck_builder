#include "mainmenu.h"

using namespace mtg::gui;

MainMenu::MainMenu()
{
    startButton.onClick = [this]
    {
        animateForward = true;
        buttonAnimator.start();
        updater.addAnimator (buttonAnimator, [this] { updater.removeAnimator (buttonAnimator); });
    };

    addAndMakeVisible (startButton);
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
    startButton.setBounds (getLocalBounds().withSizeKeepingCentre (140, 40));
}
