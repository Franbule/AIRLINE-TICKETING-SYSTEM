/*
    Author: Francisco Jesus Bueno Leon
    Date: 24/01/2024
    This program is create for the customer do booking for a flight and, the customer had to enter the information for the flight.
    The software check all format of the inputs, and print one ticket flight with the all information.
*/
#include "TicketFlight.h"
#include "Customer.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Menu.h"
#include <fstream>
#include <vector>
#include "Bank.h"
using namespace std;

// Function declarations
void setUp();
void checkUser();

// Global variables
vector<Customer> customerDataVector;
Customer customer1;
TicketFlight ticket;
Bank bank1;
string option;
int main() {
    Menu menu;

    setUp();
    unsigned short choice;

    do {
        choice = stoi(menu.readChoice());

        switch (choice) {
            case 1:
                // Function to check and process user booking
                checkUser();
                ticket.dataTickets(ticket);
                while (true) {
                cout << "\n\tDo you want to follow with the process? Enter Y(es) or N(o): ";
                cin >> option;
                if (option.length() == 1 && std::isalpha(option[0])) {
                    transform(option.begin(), option.end(), option.begin(), ::toupper);
                    if (option == "Y") {
                        bank1.SetverificationCredit(customer1);
                        bank1.sendMessage(customer1, ticket);
                        customer1.updateBalance(customer1.getUsername(), customer1.getBalance(),customer1.getCreditCardNumber(), customerDataVector);
                        if(bank1.GetPaymentVerification())
                            ticket.printTicket (customer1,ticket);
                        else
                            cout<<"Sorry the booking failed."<<endl;
                        break;
                    }
                    else if (option == "N") {
                        cout << "\n\tThank you, You will go to the booking menu.\n";
                        break;
                    }
                    else {
                       cout << "\n\tThis option is not correct, please enter \"Y\" or \"N\".\n";
                    }
                }
                else {
                    cout << "Invalid input. Please enter a single letter.\n";
                }
            }

                break;
            case 2:
                // Display user balance
                checkUser();
                cout << "\nWelcome " << customer1.getUsername() << " your balance is: " << customer1.getBalance() << endl;
                break;
        }
    } while (toupper(choice) != 3);

    return 0;
}



//Method for set Up the vector from the file
void setUp() {
    // Read customer data from file and populate the vector
    ifstream inputFile("Customer.txt");

    if (!inputFile.is_open()) {
        cout << "The file can't be open." << endl;
    }

    string username;
    float balance;
    string creditCardNumber;

    while (inputFile >> username >> balance >> creditCardNumber) {
        customerDataVector.emplace_back(username, balance, creditCardNumber);
    }

    inputFile.close();

    // Display customer data in the vector
    for (auto& Customer : customerDataVector) {
        cout << "Name: " << Customer.getUsername() << " Balance: "<< fixed << setprecision(2) << Customer.getBalance()
             << " Credit Card: " << Customer.getCreditCardNumber() << endl;
    }
}
//Method for find the user into the vector
void checkUser() {
    string checkName;
    cout << "\t\t\tEnter your Name:";
    cin >> checkName;

    // Find the user in the vector based on the entered name
    auto it = find_if(customerDataVector.begin(), customerDataVector.end(), [&checkName](const Customer& customer) {
        return customer.getUsername() == checkName;
    });

    if (it != customerDataVector.end()) {
        // If user found, update the customer1 object
        customer1 = *it;
        cout << "Name: " << it->getUsername() << ", Balance: " << it->getBalance()
             << ", Credit Card: " << it->getCreditCardNumber() << endl;
    } else {
        // If user not found, prompt for new data and add to the vector
        float newBalance;
        string newCreditCard;
        cout << "Name Not found." << endl;
        cout << checkName << " enter your balance:";
        cin >> newBalance;
        cout << checkName << " enter your Credit Card:";
        cin >> newCreditCard;
        customer1 = Customer(checkName, newBalance, newCreditCard);

        // Save the new customer to the file
        ofstream outputFile("Customer.txt", ios::app);
        if (outputFile.is_open()) {
            customer1.saveToFile(outputFile);
            outputFile.close();
        } else {
            cout << "File could not be opened for writing.\n";
        }

        // Add the new Customer to the vector
        customerDataVector.push_back(customer1);
    }
}

