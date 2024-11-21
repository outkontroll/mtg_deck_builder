#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include <juce_gui_basics/juce_gui_basics.h>

namespace mtg::gui {

class MainComponent final : public juce::Component
{
public:
    MainComponent();

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

}

#endif // MAINCOMPONENT_H
