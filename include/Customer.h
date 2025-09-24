#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <fstream>


using namespace std;

class Customer
{
public:
    // Constructors
    Customer();
    Customer(const string&, const float, const string&);

    // AGetter methods
    string getUsername() const;
    float getBalance() const;
    string getCreditCardNumber() const;

    // Setter methods
    void setUsername(const string& uname);
    void setBalance(const float bal);
    void setCreditCardNumber(const string& ccNumber);

    // File methods
    void saveToFile(ofstream& outputFile) const;  // Save customer data to a file

    // Update customer balance based on username and new balance
    void updateBalance(const string& username, float newBalance,string newCreditCard, vector<Customer>& customerDataVector);

protected:
private:
    // Data members for storing customer details
    string username;
    float balance;
    string creditCardNumber;
};

#endif // CUSTOMER_H
