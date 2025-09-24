#include "menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
// Initialise the menu text.

    this->text = "\n\n\t\t\tMorrison's Island Getaways\n\n\t\t1\tBuy a ticket\n"
                 "\t\t2\tCheck your Balance\n"
                 "\t\t3\tQuit\n";
}

string Menu::readChoice () {
// Read in and validate the menu choice. Return a valid choice.

    string option;
    bool optionOK = false;

    do {
        cout << this->text;
        cout << "\n\t\tEnter option: ";
        cin >> option;
        auto location = validOptions.find(option);
        if (location != validOptions.end ())
            optionOK = true;
        else
            cout << "\n\t\t" << option << " is not a valid option. Please re-enter when prompted.\n\n";
    }
    while (!optionOK);
    return option;
}
