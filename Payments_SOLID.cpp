#include <iostream>
#include <memory>
#include <string>
using namespace std;

// =============================
// Abstraction: Payment Strategy
// =============================
class IPayment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPayment() = default;
};

// =============================
// Concrete Payment Implementations
// =============================
class PayPalPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

class GooglePayPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing GooglePay payment of $" << amount << endl;
    }
};

class CreditCardPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Processing Credit Card payment of $" << amount << endl;
    }
};

class UnknownPayment : public IPayment {
public:
    void processPayment(double amount) override {
        cout << "Invalid payment mode selected! Amount $" 
             << amount << " not processed." << endl;
    }
};

// =============================
// Abstraction: Factory for Payments
// =============================
class IPaymentFactory {
public:
    virtual unique_ptr<IPayment> createPayment() = 0;
    virtual ~IPaymentFactory() = default;
};

// =============================
// Concrete Factories
// =============================
class PayPalFactory : public IPaymentFactory {
public:
    unique_ptr<IPayment> createPayment() override {
        return make_unique<PayPalPayment>();
    }
};

class GooglePayFactory : public IPaymentFactory {
public:
    unique_ptr<IPayment> createPayment() override {
        return make_unique<GooglePayPayment>();
    }
};

class CreditCardFactory : public IPaymentFactory {
public:
    unique_ptr<IPayment> createPayment() override {
        return make_unique<CreditCardPayment>();
    }
};

class UnknownFactory : public IPaymentFactory {
public:
    unique_ptr<IPayment> createPayment() override {
        return make_unique<UnknownPayment>();
    }
};

// =============================
// High-level Checkout (depends only on abstractions)
// =============================
void checkout(IPaymentFactory& factory, double amount) {
    auto payment = factory.createPayment();
    payment->processPayment(amount);
}

// =============================
// Example Usage
// =============================
int main() {
    double amount = 150.75;

    PayPalFactory paypal;
    GooglePayFactory gpay;
    CreditCardFactory credit;
    UnknownFactory unknown;

    checkout(paypal, amount);
    checkout(gpay, amount);
    checkout(credit, amount);
    checkout(unknown, amount);

    return 0;
}

