#include "Payment.h"
using namespace std;

void PayPalPayment::processPayment(double amount) {
    cout << "Processing PayPal payment of $" << amount << endl;
}

void GooglePayPayment::processPayment(double amount) {
    cout << "Processing GooglePay payment of $" << amount << endl;
}

void CreditCardPayment::processPayment(double amount) {
    cout << "Processing Credit Card payment of $" << amount << endl;
}

void UnknownPayment::processPayment(double amount) {
    cout << "Invalid payment mode selected! Amount $" 
         << amount << " not processed." << endl;
}
