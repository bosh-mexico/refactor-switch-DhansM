#include "Checkout.h"
#include "Factory.h"

int main() {
    double amount = 150.75;

    PayPalFactory paypal;
    GooglePayFactory gpay;
    CreditCardFactory credit;
    UnknownFactory unknown;

    Checkout::process(paypal, amount);
    Checkout::process(gpay, amount);
    Checkout::process(credit, amount);
    Checkout::process(unknown, amount);

    return 0;
}
