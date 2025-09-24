#include "Customer.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Menu.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Default constructor initializes member variables with default values.
Customer::Customer() : username(""), balance(0.0), creditCardNumber("") {}

// Parameterized constructor sets member variables with provided values.
Customer::Customer(const string& uname, const float bal, const string& ccNumber)
    : username(uname), balance(bal), creditCardNumber(ccNumber) {}

// Getter methods to access private member variables.
string Customer::getUsername() const {
    return username;
}

float Customer::getBalance() const {
    return balance;
}

string Customer::getCreditCardNumber() const {
    return creditCardNumber;
}

// Setter methods to update private member variables.
void Customer::setUsername(const string& uname) {
    username = uname;
}

void Customer::setBalance(const float bal) {
    balance = bal;
}

void Customer::setCreditCardNumber(const string& ccNumber) {
    creditCardNumber = ccNumber;
}

// Save customer information to a file.
void Customer::saveToFile(ofstream& outputFile) const {
    outputFile << getUsername() << "\n" << getBalance() << "\n" << getCreditCardNumber() << "\n";
}

// Update the balance of a specific customer and save the changes to the file.
void Customer::updateBalance(const string& username, float newBalance,string newCreditCard, vector<Customer>& customerDataVector) {
    // Find the customer in the vector based on the provided username.
    auto it = find_if(customerDataVector.begin(), customerDataVector.end(),
                      [&username](const Customer& customer) {
                          return customer.getUsername() == username;
                      });
    // Check if the customer was found.
    if (it != customerDataVector.end()) {
        // Update the balance with the new value.
        it->setBalance(newBalance);
        it->setCreditCardNumber(creditCardNumber);
    } else {
        // Display a message if the user is not found.
        cout << "User not found in the vector." << endl;
        return; // Exit early if the user is not found.
    }

    // Open the file for writing.
    ofstream outputFile("Customer.txt");

    if (outputFile.is_open()) {
        // Write the updated information of all customers to the file.
        for (const auto& customer : customerDataVector) {
            customer.saveToFile(outputFile);
        }

        // Close the file.
        outputFile.close();
    } else {
        // Display an error message if the file cannot be opened.
        cout << "Error: Could not open the file for writing." << endl;
    }
}
