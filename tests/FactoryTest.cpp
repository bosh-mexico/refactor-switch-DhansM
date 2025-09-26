#include "Factory.h"
#include <gtest/gtest.h>

TEST(FactoryTest, PayPalFactoryCreatesPayPalPayment) {
    PayPalFactory factory;
    auto payment = factory.createPayment();
    EXPECT_NE(dynamic_cast<PayPalPayment*>(payment.get()), nullptr);
}

TEST(FactoryTest, GooglePayFactoryCreatesGooglePayPayment) {
    GooglePayFactory factory;
    auto payment = factory.createPayment();
    EXPECT_NE(dynamic_cast<GooglePayPayment*>(payment.get()), nullptr);
}

TEST(FactoryTest, CreditCardFactoryCreatesCreditCardPayment) {
    CreditCardFactory factory;
    auto payment = factory.createPayment();
    EXPECT_NE(dynamic_cast<CreditCardPayment*>(payment.get()), nullptr);
}

TEST(FactoryTest, UnknownFactoryCreatesUnknownPayment) {
    UnknownFactory factory;
    auto payment = factory.createPayment();
    EXPECT_NE(dynamic_cast<UnknownPayment*>(payment.get()), nullptr);
}
