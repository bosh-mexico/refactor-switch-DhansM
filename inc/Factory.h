#ifndef FACTORY_H
#define FACTORY_H

#include "Payment.h"

class IPaymentFactory {
public:
    virtual std::unique_ptr<IPayment> createPayment() = 0;
    virtual ~IPaymentFactory() = default;
};

class PayPalFactory : public IPaymentFactory {
public:
    std::unique_ptr<IPayment> createPayment() override;
};

class GooglePayFactory : public IPaymentFactory {
public:
    std::unique_ptr<IPayment> createPayment() override;
};

class CreditCardFactory : public IPaymentFactory {
public:
    std::unique_ptr<IPayment> createPayment() override;
};

class UnknownFactory : public IPaymentFactory {
public:
    std::unique_ptr<IPayment> createPayment() override;
};

#endif // FACTORY_H
