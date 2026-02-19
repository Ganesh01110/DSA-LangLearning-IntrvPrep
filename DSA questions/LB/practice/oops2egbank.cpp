#include <iostream>
#include <string>
using namespace std;

// Encapsulation: Data members are private, accessed through public methods
class BankAccount {
private:
    string owner;
    double balance;

public:
    // Constructor to initialize the object
    BankAccount(string name, double initialBalance) : owner(name), balance(initialBalance) {}

    // Getter methods to access private data
    string getOwner() const { return owner; }
    double getBalance() const { return balance; }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account of " << owner << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account of " << owner << endl;
        } else {
            cout << "Invalid or insufficient amount!" << endl;
        }
    }

    // Virtual function to demonstrate polymorphism
    virtual void accountType() const {
        cout << "General Bank Account of " << owner << endl;
    }
};

// Inheritance: SavingsAccount inherits from BankAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor: Calls base class constructor to initialize owner and balance
    SavingsAccount(string name, double balance, double rate) 
        : BankAccount(name, balance), interestRate(rate) {}

    // Polymorphism: Overriding the virtual function
    void accountType() const override {
        cout << "Savings Account with interest rate of " << interestRate << "%" << endl;
    }

    // Method to apply interest
    void applyInterest() {
        double interest = (getBalance() * interestRate) / 100;
        deposit(interest);
        cout << "Interest of $" << interest << " applied to account of " << getOwner() << endl;
    }
};

// Abstraction: A pure virtual class
class Loan {
public:
    // Pure virtual function for loan details
    virtual void loanDetails() const = 0;
};

// Derived class implementing the abstract class Loan
class HomeLoan : public Loan {
public:
    void loanDetails() const override {
        cout << "Home loan with low interest rates and flexible payment options." << endl;
    }
};

// Polymorphism: Function overloading
class Calculator {
public:
    int multiply(int a, int b) {
        return a * b;
    }

    double multiply(double a, double b) {
        return a * b;
    }
};

// Operator Overloading: Example for overloading "-" operator
class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize distance
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {}

    // Overloading "-" operator to subtract two distances
    Distance operator - (const Distance& d) {
        int totalInches1 = (feet * 12) + inches;
        int totalInches2 = (d.feet * 12) + d.inches;
        int diffInches = totalInches1 - totalInches2;

        return Distance(diffInches / 12, diffInches % 12);
    }

    // Method to display distance
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    // Demonstrating encapsulation
    BankAccount account("John Doe", 1000.0);
    account.deposit(200);
    account.withdraw(150);

    // Demonstrating inheritance and polymorphism
    SavingsAccount savings("Alice", 5000.0, 5.0);  // 5% interest rate
    savings.accountType();
    savings.applyInterest();

    // Demonstrating abstraction
    HomeLoan homeLoan;
    homeLoan.loanDetails();

    // Demonstrating polymorphism: Function overloading
    Calculator calc;
    cout << "Product of integers: " << calc.multiply(10, 20) << endl;
    cout << "Product of doubles: " << calc.multiply(2.5, 3.5) << endl;

    // Demonstrating operator overloading
    Distance d1(5, 9), d2(3, 4);  // d1 = 5 feet 9 inches, d2 = 3 feet 4 inches
    Distance d3 = d1 - d2;  // Subtracting distances using overloaded "-" operator
    cout << "Difference between distances: ";
    d3.display();

    return 0;
}


/*
Encapsulation:

The BankAccount class has private data members owner and balance, which are accessed and modified via public methods (deposit, withdraw, getOwner, etc.).
Inheritance:

The SavingsAccount class inherits from BankAccount and extends its functionality by adding an interestRate attribute and an applyInterest method.
Polymorphism:

Function Overriding: The SavingsAccount class overrides the accountType method of BankAccount.
Function Overloading: The Calculator class demonstrates overloading of the multiply function with both integer and double parameters.
Abstraction:

The Loan class is an abstract class with a pure virtual method loanDetails. The HomeLoan class implements this method.
Operator Overloading:

The Distance class overloads the - operator to subtract two Distance objects, allowing for easy subtraction of distances.
*/