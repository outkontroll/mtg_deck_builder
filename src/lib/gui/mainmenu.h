#ifndef MAINMENU_H
#define MAINMENU_H

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_animation/juce_animation.h>

namespace mtg::gui {

class MainMenu : public juce::Component
{
public:
    MainMenu();

    void setOnAnimatedClickEnd (std::function<void()> onClickIn);
    void reset();
    void resized() override;

private:
    juce::TextButton startButton { "New game" };
    bool animateForward = false;
    juce::Animator buttonAnimator = [&]
    {
        return juce::ValueAnimatorBuilder{}
            .withOnStartCallback ([this] { setVisible (true); })
            .withValueChangedCallback ([this] (auto value)
                                      {
                                          const auto progress = animateForward ? value : (1.0 - value);
                                          setAlpha (1.0f - (float) progress);
                                      })
            .withOnCompleteCallback ([this]
                                    {
                                        setVisible (! animateForward);

                                        if (animateForward)
                                            juce::NullCheckedInvocation::invoke (onClick);
                                    })
            .build();
    }();

    juce::VBlankAnimatorUpdater updater { this };
    std::function<void()> onClick;
};

}

#endif // MAINMENU_H
