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
    juce::Animator createButtonAnimator();

    juce::TextButton newGameButton { "New game" };
    bool animateForward = false;
    juce::Animator buttonAnimator = createButtonAnimator();

    juce::VBlankAnimatorUpdater updater { this };
    std::function<void()> onClick;
};

}

#endif // MAINMENU_H
