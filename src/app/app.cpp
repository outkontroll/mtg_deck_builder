#include "app.h"

using namespace mtg;

namespace {

constexpr auto appHeader = "Mtg Deck Builder";

}

const juce::String MtgApplication::getApplicationName()
{
    return JUCE_APPLICATION_NAME_STRING;
}

const juce::String MtgApplication::getApplicationVersion()
{
    return JUCE_APPLICATION_VERSION_STRING;
}

bool MtgApplication::moreThanOneInstanceAllowed()
{
    return true;
}

void MtgApplication::initialise(const juce::String& commandLine)
{
    juce::ignoreUnused (commandLine);

    mainWindow.reset (new gui::MainWindow(appHeader));
}

void MtgApplication::shutdown()
{
    mainWindow = nullptr;
}

void MtgApplication::systemRequestedQuit()
{
    quit();
}

void MtgApplication::anotherInstanceStarted(const juce::String& commandLine)
{
    juce::ignoreUnused (commandLine);
}
