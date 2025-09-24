#include "TicketFlight.h"
#include <cctype>
#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// Default constructor initializes member variables with default values.
TicketFlight::TicketFlight()
{
    this->flightClass = ' ';
    this->depDate = "";
    this->depTime = "";
    this->arrDate = "";
    this->arrTime = "";
    this->costF = 0.0;
}

// Method to set the flight class (Economy or Business).
void TicketFlight::SetflightClass()
{
    string fClass;
    bool valid = false;
    while (!valid)
    {
        cout << "\nEnter the Class Flight (E = Economy or B = Business): ";
        cin >> fClass;
        if (fClass.length() == 1 && isalpha(fClass[0])) {
            transform(fClass.begin(), fClass.end(), fClass.begin(), ::toupper);
            if (fClass == "E" || fClass == "B")
            {
                this->flightClass = fClass;
                valid = true;
            }
            else
                cout << "\n\tPlease, enter just a letter E or B.";

        }
    }
}

// Method to set the departure airport.
void TicketFlight::SetdepAir()
{
    string dAir;
    bool valid = false;

    while (!valid)
    {
        bool valid1 = true;
        cout << "\n\tEnter the Departure Airport: ";
        cin >> dAir;

        if (dAir.length() != 3)
        {
            cout << "\t\tSorry, the Departure Airport must be 3 letters.";
            valid1 = false;
        }

        if (valid1)
        {
            for (unsigned short i = 0; i < dAir.length(); ++i)
            {
                if (!isalpha(dAir[i]))
                {
                    valid = false;
                    valid1 = false;
                    cout << "\n\tSorry, the Departure Airport must be letters.";
                }
            }
        }
        if (valid1)
        {
            for (unsigned short i = 0; i < dAir.length(); ++i)
            {
                dAir[i] = toupper(dAir[i]);
            }
            this->depAir = dAir;
            valid = true;
        }
    }
}

// Method to set the departure date.
void TicketFlight::SetdepDate()
{
    Date dateDep;
    dateDep.setDate("Departure");
    this->depDate = dateDep.GetDate();
}

// Method to set the departure time.
void TicketFlight::SetdepTime()
{
    Date timeDep;
    timeDep.setTime("Departure");
    this->depTime = timeDep.GetTime();
}

// Method to set the arrival airport.
void TicketFlight::SetarrAir()
{
    string aAir;
    bool valid = false;

    while (!valid)
    {
        bool valid1 = true;
        cout << "\n\tEnter the Arrival Airport: ";
        cin >> aAir;

        if (aAir.length() != 3)
        {
            cout << "\n\t\tSorry, the Arrival Airport must be 3 letters.";
            valid1 = false;
        }

        if (valid1)
        {
            for (unsigned short i = 0; i < aAir.length(); ++i)
            {
                if (!isalpha(aAir[i]))
                {
                    valid = false;
                    valid1 = false;
                    cout << "\n\t\tSorry, the Arrival Airport must be letters.";
                }
            }
        }
        if (valid1)
        {
            for (unsigned short i = 0; i < aAir.length(); ++i)
            {
                aAir[i] = toupper(aAir[i]);
            }
            this->arrAir = aAir;
            valid = true;
        }
    }
}

// Method to set the arrival date.
void TicketFlight::SetarrDate()
{
    Date dateArr;
    dateArr.setDate("Arrival");
    this->arrDate = dateArr.GetDate();
}

// Method to set the arrival time.
void TicketFlight::SetarrTime()
{
    Date timeArr;
    timeArr.setTime("Arrival");
    this->arrTime = timeArr.GetTime();
}

// Method to set the cost of the flight.
void TicketFlight::SetCostF()
{
    float cFlight;
    cout << "\n\tEnter the Cost of the Flight: ";
    cin >> cFlight;

    // Validate input to ensure it is a number.
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\t\tEnter the Cost of the Flight (Just Numbers):";
        cin >> cFlight;
    }

    this->costF = cFlight;
}
//Method to call all set method
void TicketFlight::dataTickets(TicketFlight& ticket) {
    cout << "\n\t\tWelcome to the Booking Ticket";
    // Call Method to set the flight class
    ticket.SetflightClass();
    // Call Methods to set departure and arrival details
    ticket.SetdepAir();
    ticket.SetdepDate();
    ticket.SetdepTime();
    ticket.SetarrTime();
    ticket.SetarrDate();
    ticket.SetarrAir();
    // Call Method to set the Cost of the flight
    ticket.SetCostF();

    cout << "\n\t\tYour Booking is processing, we are going to check with the bank.";
}

//Method for print the ticket
void TicketFlight::printTicket(Customer& customer,TicketFlight& ticket) {
    // Display the ticket details
    cout << left << setw(20) << "NAME: " << setw(30) << customer.getUsername() << "CLASS: " << setw(20) << ticket.GetflightClass() << "COST: " << fixed << setprecision(2) << ticket.GetCostF() << "\n\n";
    cout << setw(20) << "DEPARTING" << setw(20) << "DATE" << setw(20) << "TIME" << endl;
    cout << setw(20) << ticket.GetdepAir() << setw(20) << ticket.GetdepDate() << setw(20) << ticket.GetdepTime() << "\n\n";
    cout << setw(20) << "ARRIVING" << setw(20) << "DATE" << setw(20) << "TIME" << endl;
    cout << setw(20) << ticket.GetarrAir() << setw(20) << ticket.GetarrDate() << setw(20) << ticket.GetarrTime() << endl;
}
