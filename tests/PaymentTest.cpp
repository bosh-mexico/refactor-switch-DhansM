#include "Payment.h"
#include <gtest/gtest.h>
#include <sstream>

// Helper: redirect cout to string
std::string captureOutput(std::function<void()> func) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(PaymentTest, PayPalPaymentOutput) {
    PayPalPayment paypal;
    auto output = captureOutput([&]() { paypal.processPayment(100.0); });
    EXPECT_NE(output.find("Processing PayPal payment of $100"), std::string::npos);
}

TEST(PaymentTest, GooglePayPaymentOutput) {
    GooglePayPayment gpay;
    auto output = captureOutput([&]() { gpay.processPayment(50.5); });
    EXPECT_NE(output.find("Processing GooglePay payment of $50.5"), std::string::npos);
}

TEST(PaymentTest, CreditCardPaymentOutput) {
    CreditCardPayment card;
    auto output = captureOutput([&]() { card.processPayment(75.25); });
    EXPECT_NE(output.find("Processing Credit Card payment of $75.25"), std::string::npos);
}

TEST(PaymentTest, UnknownPaymentOutput) {
    UnknownPayment unknown;
    auto output = captureOutput([&]() { unknown.processPayment(10.0); });
    EXPECT_NE(output.find("Invalid payment mode selected!"), std::string::npos);
}
