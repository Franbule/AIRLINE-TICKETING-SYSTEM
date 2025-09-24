#ifndef MENU_H
#define MENU_H

#include <set>
#include <string>

using namespace std;

class Menu
{
    public:
        Menu();
        string readChoice ();

    private:
        set<string> validOptions = {"1", "2", "3", "4"};
        string text;
};

#endif // MENU_H
