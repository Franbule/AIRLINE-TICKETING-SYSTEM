#include "Bank.h"
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <regex>
#include <iomanip>

using namespace std;

// Default constructor initializes member variables with default values.
Bank::Bank()
{
   this->verificationCredit = false;
   this->code = 0000;
}

// Method to set the credit card verification for a customer.
void Bank::SetverificationCredit(Customer& customer)
{
    bool payOk = false;
    string creditCard;
    regex creditRegex(R"(\d{4}-\d{4}-\d{4}-\d{4})");

    // Loop until a valid credit card number is provided.
    while (!payOk)
    {
        // Check if the credit card number has the correct format.
        if (!regex_match(customer.getCreditCardNumber(),creditRegex))
        {
            cout << "\nPlease, your credit card number is not correct.";
            cout << "\n\t\tEnter again the number of your credit card(***-****-***-***):";
            cin >> creditCard;

            // Validate input to ensure it is a 16-digit number.
            while (cin.fail() || !regex_match(creditCard,creditRegex))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t\tEnter again the number of your credit card(***-****-***-***):";
                cin >> creditCard;
            }
            // Update the customer's credit card number.
            customer.setCreditCardNumber(creditCard);
        }

        payOk = true;
    }

    // Set credit verification status.
    this->verificationCredit = payOk;
}
void Bank::setPaymentVerification(bool value){

    this->paymentVerification = value;
}
// Method to generate a random verification code (PIN).
void Bank::setCode()
{
    time_t now = time(0);
    char* date_time = ctime(&now);
    // Generate a random 4-digit number as the verification code.
    unsigned short randomNumber;
    srand(time(0));
    randomNumber = rand() % 9000 + 1000;
    cout << "\n\t\tAIB BANK\n\t"<< date_time <<"\nPin for Verification: " << randomNumber;

    // Set the generated code.
    this->code = randomNumber;
}

// Method to send a message and verify payment.
void Bank::sendMessage(Customer& customer, TicketFlight& ticket)
{
    unsigned short attempts = 0;
    unsigned short userCode;

    // Generate and display the verification code.
    setCode();

    // Check if credit card verification is successful.
    if (this->verificationCredit == true)
    {
        cout << "\tEnter the Pin (Bank sent you):";
        cin >> userCode;

       // Validate input to ensure it is a 4-digit number and limit to 3 attempts.
        while (attempts < 3) {
            // Check if the input is a number and is equal to the generated code.
            if (cin.fail() || userCode != this->code) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\tThe Pin is incorrect, please enter again: ";
                cin >> userCode;
                attempts += 1;
            } else {
                // Correct input, break out of the loop.
                break;
            }
        }
        // Check if the user entered the correct code within the allowed attempts.
        if (attempts == 3) {
            cout << "\n\tYou have exceeded the maximum number of attempts. Payment canceled.\n";
            setPaymentVerification(false);
        }
        else{
            cout<<"The pin is correct";
            // Check if the customer's balance is sufficient for the ticket cost.
            if (customer.getBalance() > ticket.GetCostF())
            {
                // Deduct the ticket cost from the customer's balance.
                float newBalance = customer.getBalance() - ticket.GetCostF();
                customer.setBalance(newBalance);
            }
            else
            {
                float newBalance;
                cout << "\n\tYour Balance is not enough.";
                cout << "\n\tTop-Up your Balance:";
                cin >> newBalance;
                // Validate input to ensure it is a valid number.
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\t\tEnter again your new Balance (just numbers):";
                    cin >> newBalance;
                }
                // Update the customer's balance.
                customer.setBalance(customer.getBalance() + newBalance);
                newBalance = customer.getBalance() - ticket.GetCostF();
                customer.setBalance(newBalance);
            }

        cout << "\n\t\tCongratulations! Your Payment was successful!\n\tYour Booking code is \"MIG"
        << ticket.GetdepDate() << ticket.GetdepAir() << ticket.GetarrAir() << endl;
        cout << "\n\t\tYour new Balance is: " <<fixed << setprecision(2) << customer.getBalance()<<"\n\n";
        setPaymentVerification(true);
        }
    }

}
