#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <juce_gui_extra/juce_gui_extra.h>

namespace mtg::gui {

class MainWindow final : public juce::DocumentWindow
{
public:
    explicit MainWindow (juce::String name);

    void closeButtonPressed() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
};

}

#endif // MAINWINDOW_H
