#ifndef NEWGAMEPANEL_H
#define NEWGAMEPANEL_H

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_animation/juce_animation.h>

namespace mtg::gui {

class NewGamePanel : public juce::Component
{
public:
    NewGamePanel();

    void paint (juce::Graphics& g) override;
    void resized() override;

    void open();
    void close();

    std::function<void()> onClose;
    std::function<void()> onStartGame;

private:
    void startGame();
    void updateGameModeSelection(juce::ToggleButton& button);
    void showClassicDecks();
    void showCommanderDecks();

    juce::Animator createSlideInAnimator();

    juce::DropShadow shadow { juce::Colour { 0x90000000 }, 12, {} };
    juce::DropShadower shadower { shadow };
    juce::TextButton closeButton { "X" };
    juce::TextButton startGameButton { "Start Game" };
    juce::ToggleButton gameModeClassicButton { "1v1" };
    juce::ToggleButton gameModeCommanderButton { "Commander" };

    juce::Animator slideInAnimator = createSlideInAnimator();

    juce::VBlankAnimatorUpdater updater { this };
    bool shouldOpen = true;

};

}

#endif // NEWGAMEPANEL_H
