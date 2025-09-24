#ifndef TICKETFLIGHT_H
#define TICKETFLIGHT_H

#include "Customer.h"
#include "Date.h"
#include <string>

using namespace std;

class TicketFlight
{
public:
    // Default constructor
    TicketFlight();

    // Getter and setter for flightClass
    string GetflightClass() const { return flightClass; }
    void SetflightClass();

    // Getter and setter for depAir
    string GetdepAir() const { return depAir; }
    void SetdepAir();

    // Getter and setter for depDate
    string GetdepDate() const { return depDate; }
    void SetdepDate();

    // Getter and setter for depTime
    string GetdepTime() const { return depTime; }
    void SetdepTime();

    // Getter and setter for arrAir
    string GetarrAir() const { return arrAir; }
    void SetarrAir();

    // Getter and setter for arrDate
    string GetarrDate() const { return arrDate; }
    void SetarrDate();

    // Getter and setter for arrTime
    string GetarrTime() const { return arrTime; }
    void SetarrTime();

    // Getter and setter for costF
    float GetCostF() const { return costF; }
    void SetCostF();

    void dataTickets(TicketFlight& ticket);
    void printTicket(Customer& customer,TicketFlight& ticket);

protected:

private:
    // Data members for storing ticket details
    string flightClass;
    string depAir;
    string depDate;
    string depTime;
    string arrAir;
    string arrDate;
    string arrTime;
    float costF;
};

#endif // TICKETFLIGHT_H
