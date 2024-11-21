#include "mainwindow.h"
#include "MainComponent.h"

using namespace mtg::gui;

MainWindow::MainWindow(juce::String name)
    : DocumentWindow (name,
                     juce::Desktop::getInstance().getDefaultLookAndFeel()
                         .findColour (ResizableWindow::backgroundColourId),
                     DocumentWindow::allButtons)
{
    setUsingNativeTitleBar (true);
    setContentOwned (new MainComponent(), true);

#if JUCE_IOS || JUCE_ANDROID
    setFullScreen (true);
#else
    setResizable (true, true);
    centreWithSize (getWidth(), getHeight());
#endif

    setVisible (true);
}

void MainWindow::closeButtonPressed()
{
    // This is called when the user tries to close this window. Here, we'll just
    // ask the app to quit when this happens, but you can change this to do
    // whatever you need.
    juce::JUCEApplication::getInstance()->systemRequestedQuit();
}
