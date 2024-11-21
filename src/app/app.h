#ifndef APP_H
#define APP_H

#include "mainwindow.h"

namespace mtg {

class MtgApplication final : public juce::JUCEApplication
{
public:
    MtgApplication() = default;

    const juce::String getApplicationName() override;
    const juce::String getApplicationVersion() override;
    bool moreThanOneInstanceAllowed() override;
    void initialise (const juce::String& commandLine) override;
    void shutdown() override;
    void systemRequestedQuit() override;
    void anotherInstanceStarted (const juce::String& commandLine) override;

private:
    std::unique_ptr<gui::MainWindow> mainWindow;
};

}

#endif // APP_H
