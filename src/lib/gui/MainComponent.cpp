#include "MainComponent.h"

using namespace mtg::gui;

MainComponent::MainComponent()
{
    mainMenu.setOnAnimatedClickEnd ([this](){
        newGamePanel.open();
    });

    addAndMakeVisible (mainMenu);

    newGamePanel.onClose = [this] { mainMenu.reset(); };
    newGamePanel.onStartGame = [] {
        std::cout << "Start Game" << "\n";
    };

    addAndMakeVisible (newGamePanel);

    setSize (600, 400);
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    mainMenu.setBounds (getLocalBounds());
}
