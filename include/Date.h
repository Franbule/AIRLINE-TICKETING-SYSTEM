#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
public:
    // Default constructor
    Date();

    // Member functions to set date and time
    void setDate(string);
    void setTime(string);

    // Getter functions for retrieving date and time
    string GetDate() const { return date; }
    string GetTime() const { return time; }

private:
    // Private data members to store date and time
    string date;
    string time;
};

#endif // DATE_H
