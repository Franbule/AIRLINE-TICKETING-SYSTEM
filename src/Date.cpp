#include "Date.h"
#include <iostream>
#include <regex>
#include <iomanip>

using namespace std;

// Default constructor initializes member variables with default values.
Date::Date()
{
    this->date = "28/01/2024";
    this->time = "12:45";
}

// Method to set the date with user input.
void Date::setDate(string value)
{
    bool valid = true;
    string DoA = value;
    string setDate;
    // Regular expression to validate the date format (DD/MM/YYYY).
    regex dateRegex(R"((0[1-9]|[0-9][0-9])/(0[0-9]|[0-9][0-9])/2024)");

    do
    {
        cout << "\n\n\tEnter the " << DoA << " Date (DD/MM/YYYY): ";
        cin >> setDate;

        // Validate the entered date using the regular expression.
      if (!regex_match(setDate, dateRegex))
        {
            cout << "\t\tThe format of the date must be DD/MM/YYYY";
            valid = false;
        }
        else
        {
            if (stoi(setDate.substr(0, 2)) < 1 || stoi(setDate.substr(0, 2))> 31)
            {
                cout << "\t\tThe day must be between 1 and 31";
                valid = false;
            }
            else if (stoi(setDate.substr(3, 2)) < 1 || stoi(setDate.substr(3, 2)) > 12)
            {
                cout << "\t\tThe month must be between 1 and 12";
                valid = false;
            }
            else if (stoi(setDate.substr(6, 4)) < 2023)
            {
                cout << "\t\tThe Year must be 2024";
                valid = false;
            }
            else
            {
                valid = true;
            }
        }
    } while (!valid);
    // Update the date member variable with the validated date.
    this->date = setDate;
}

// Method to set the time with user input.
void Date::setTime(string value)
{
    bool valid = true;
    string DoA = value;
    string setTime;
    // Regular expression to validate the time format (HH:MM).
    regex timeRegex(R"((0[0-9]|[0-9][0-9]):[0-9][0-9])");

    do
    {
        cout << "\n\n\tEnter the " << DoA << " Time (HH:MM): ";
        cin >> setTime;

        // Validate the entered time using the regular expression.
        if (!regex_match(setTime, timeRegex))
        {
            cout << "Format of Time incorrect. Try Again.\n" << endl;
            valid = false;
        }
        else
        {
             if (stoi(setTime.substr(0, 2)) < 0 || stoi(setTime.substr(0, 2))> 23)
            {
                cout << "\t\tThe Hours must be between 00 and 23";
                valid = false;
            }
            else if (stoi(setTime.substr(3, 2)) < 0 || stoi(setTime.substr(3, 2)) > 59)
            {
                cout << "\t\tThe Minutes must be between 00 and 59";
                valid = false;
            }
            else
                valid = true;
        }

    } while (!valid);

    // Update the time member variable with the validated time.
    this->time = setTime;
}
