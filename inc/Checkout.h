
#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "Factory.h"

class Checkout {
public:
    static void process(IPaymentFactory& factory, double amount);
};

#endif // CHECKOUT_H
