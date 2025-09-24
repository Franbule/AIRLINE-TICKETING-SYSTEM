#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Customer.h"
#include "TicketFlight.h"

class Bank
{
public:
    // Default constructor
    Bank();

    // Getter for verificationCredit
    bool GetverificationCredit() const { return verificationCredit; }

    // Function to set verificationCredit based on customer's credit card
    void SetverificationCredit(Customer& customer);

    // Getter for the verification code
    unsigned short GetCode() const { return code; }

    // Function to generate and set a verification code
    void setCode();

    // Function to send a message to the customer based on payment verification
    void sendMessage(Customer& customer, TicketFlight& ticket);

    void setPaymentVerification(bool value);

    bool GetPaymentVerification() {return paymentVerification;}

protected:

private:
    // Data member to store payment verification status
    bool verificationCredit;

    // Data member to store the verification code
    unsigned short code;

    bool paymentVerification;
};

#endif // BANK_H
