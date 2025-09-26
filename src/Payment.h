#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <memory>
#include <string>

class IPayment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPayment() = default;
};

class PayPalPayment : public IPayment {
public:
    void processPayment(double amount) override;
};

class GooglePayPayment : public IPayment {
public:
    void processPayment(double amount) override;
};

class CreditCardPayment : public IPayment {
public:
    void processPayment(double amount) override;
};

class UnknownPayment : public IPayment {
public:
    void processPayment(double amount) override;
};

#endif // PAYMENT_H
