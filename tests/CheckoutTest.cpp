#include "Checkout.h"
#include "Factory.h"
#include <gtest/gtest.h>
#include <sstream>

// Helper to capture cout
std::string captureOutput(std::function<void()> func) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(CheckoutTest, ProcessesPayPalPayment) {
    PayPalFactory factory;
    auto output = captureOutput([&]() { Checkout::process(factory, 200.0); });
    EXPECT_NE(output.find("Processing PayPal payment"), std::string::npos);
}

TEST(CheckoutTest, ProcessesGooglePayPayment) {
    GooglePayFactory factory;
    auto output = captureOutput([&]() { Checkout::process(factory, 300.0); });
    EXPECT_NE(output.find("Processing GooglePay payment"), std::string::npos);
}

TEST(CheckoutTest, ProcessesCreditCardPayment) {
    CreditCardFactory factory;
    auto output = captureOutput([&]() { Checkout::process(factory, 500.0); });
    EXPECT_NE(output.find("Processing Credit Card payment"), std::string::npos);
}

TEST(CheckoutTest, HandlesUnknownPayment) {
    UnknownFactory factory;
    auto output = captureOutput([&]() { Checkout::process(factory, 999.0); });
    EXPECT_NE(output.find("Invalid payment mode selected!"), std::string::npos);
}
