#ifndef TICKET_H
#define TICKET_H

using namespace std;

class Ticket
{
    public:
        Ticket();
        Ticket(char&,string&,int&,string&,string&,string&,int&);

    protected:

    private:
        char flightClass;
        string depAir;
        string depDate;
        int depTime;
        string arrAir;
        string arrDate;
        int arrTime;
};

#endif // TICKET_H
