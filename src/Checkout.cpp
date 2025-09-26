#include "Checkout.h"

void Checkout::process(IPaymentFactory& factory, double amount) {
    auto payment = factory.createPayment();
    payment->processPayment(amount);
}
