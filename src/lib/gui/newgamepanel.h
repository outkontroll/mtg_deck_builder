#ifndef NEWGAMEPANEL_H
#define NEWGAMEPANEL_H

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_animation/juce_animation.h>

namespace mtg::gui {

class NewGamePanel : public juce::Component
{
    static constexpr auto margin = 15;
public:
    NewGamePanel();

    void paint (juce::Graphics& g) override;
    void resized() override;

    void open();
    void close();

private:
    juce::DropShadow shadow { juce::Colour { 0x90000000 }, 12, {} };
    juce::DropShadower shadower { shadow };
    juce::TextButton closeButton { "X" };

    juce::Animator slideInAnimator = juce::ValueAnimatorBuilder{}
                                   .withEasing (juce::Easings::createEaseInOutCubic())
                                   .withOnStartReturningValueChangedCallback (
                                       [this]
                                       {
                                           const auto width = getParentWidth() - 2 * margin;
                                           const auto height = 130;
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

    juce::VBlankAnimatorUpdater updater { this };
    bool shouldOpen = true;

public:
    std::function<void()> onClose;
};

}

#endif // NEWGAMEPANEL_H
