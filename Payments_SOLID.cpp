#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Base Interface for Payment Strategy
class IPayment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPayment() = default;
};

// PayPal Payment
class PayPalPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
        // Add PayPal-specific logic here
    }
};

// GooglePay Payment
class GooglePayPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing GooglePay payment of $" << amount << endl;
        // Add GooglePay-specific logic here
    }
};

// Credit Card Payment
class CreditCardPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing Credit Card payment of $" << amount << endl;
        // Add Credit Card-specific logic here
    }
};

// Unknown Payment (Graceful handling)
class UnknownPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Invalid payment mode selected! Amount $" << amount << " not processed." << endl;
    }
};

// Checkout Function (depends only on abstraction)
void checkout(unique_ptr<IPayment> payment, double amount) {
    payment->processPayment(amount);
}

// Example Usage
int main() {
    double amount = 150.75;

    checkout(make_unique<PayPalPayment>(), amount);
    checkout(make_unique<GooglePayPayment>(), amount);
    checkout(make_unique<CreditCardPayment>(), amount);
    checkout(make_unique<UnknownPayment>(), amount);

    return 0;
}
