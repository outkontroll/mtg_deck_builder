#include <iostream>
#include <string>
#include "card.h"
#include "card_reader.h"

#define IDE_PRINTER 1

using namespace card_reader;

class MainWindow
{
public:
    MainWindow(std::vector<mtg_card::Card>&& cards);
    void run();

private:
    void printMenu();
    bool takeAction(char answer);
    void printCount();
    void printCardInfo(size_t index);
    size_t getCardInfo();

    std::vector<mtg_card::Card> cards;
};

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Missing argument\n";
        return -1;
    }

    std::cout << "Reading cards from " << argv[1] << std::endl;

    MainWindow window{CardReader{}.readCards(argv[1])};
    window.run();

    return 0;
}

MainWindow::MainWindow(std::vector<mtg_card::Card>&& cards)
    : cards(std::move(cards))
{}

void MainWindow::run()
{
    if(cards.empty())
    {
        std::cout << "No cards could read" << std::endl;
        return;
    }
    else
    {
        std::cout << "Card count: " << cards.size() << std::endl;
    }

    bool canQuit = false;
    while(!canQuit)
    {
        printMenu();
        char ch;
#if IDE_PRINTER
        ch = 'i';
#else
        std::cin >> ch;
#endif
        canQuit = takeAction(ch);
    }
}

void MainWindow::printMenu()
{
    std::cout << "Options:\n";
    std::cout << "Card count: c\n";
    std::cout << "Print card info: i #\n";
    std::cout << "Choose option: ";
}

bool MainWindow::takeAction(char answer)
{
    switch (answer) {
    case 'c':
        printCount();
        return false;
    case 'i':
        printCardInfo(getCardInfo());
        return true;
    default:
        return true;
    }
}

void MainWindow::printCount()
{
    std::cout << "Card count: " << cards.size() << "\n";
}

void MainWindow::printCardInfo(size_t index)
{
    std::cout << "\n" << cards[index].name << "\n";
    for(const auto type : cards[index].types)
        std::cout << to_string(type) << " ";
    if(cards[index].manaCost)
        std::cout << "\nMana: " << *cards[index].manaCost;
    std::cout << "\nConverted manacost: " << cards[index].convertedManaCost;
    std::cout << "\nColors: " << to_string(cards[index].colors);
    std::cout << "\n" << std::endl;
}

size_t MainWindow::getCardInfo()
{
    std::string index;
#if IDE_PRINTER
    index = "0";
#else
    std::cin >> index;
#endif
    return static_cast<size_t>(std::stoi(index));
}
