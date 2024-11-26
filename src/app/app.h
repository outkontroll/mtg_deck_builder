#ifndef APP_H
#define APP_H

#include <juce_gui_basics/juce_gui_basics.h>

namespace mtg {

namespace gui {
class MainWindow;
}

class MtgApplication final : public juce::JUCEApplication
{
public:
    MtgApplication();
    ~MtgApplication() override;

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
