#include "Factory.h"

std::unique_ptr<IPayment> PayPalFactory::createPayment() {
    return std::make_unique<PayPalPayment>();
}

std::unique_ptr<IPayment> GooglePayFactory::createPayment() {
    return std::make_unique<GooglePayPayment>();
}

std::unique_ptr<IPayment> CreditCardFactory::createPayment() {
    return std::make_unique<CreditCardPayment>();
}

std::unique_ptr<IPayment> UnknownFactory::createPayment() {
    return std::make_unique<UnknownPayment>();
}
