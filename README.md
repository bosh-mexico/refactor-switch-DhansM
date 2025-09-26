### Functional Requirements

#### Payment Modes

The system must support the following payment modes:

- PayPal

- GooglePay

- CreditCard

- Any unsupported or invalid payment mode should be handled gracefully with an error message.

### Checkout Function

The system must provide a function named checkout that:

- Takes a PaymentMode (enum) as input.

- Takes the payment amount (double) as input.

- Processes the payment based on the selected PaymentMode.

### Processing Logic

For each payment mode, the system must print a confirmation message indicating:

- The selected payment mode.

- The amount being processed.

- Placeholder logic should be available for future integration with actual payment processing APIs.

#### C++ Implementtaion
```
#include <iostream>
#include <string>
using namespace std;

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Checkout function
void checkout(PaymentMode mode, double amount) {
    switch (mode) {
        case PaymentMode::PayPal:
            cout << "Processing PayPal payment of $" << amount << endl;
            // Add PayPal-specific logic here
            break;

        case PaymentMode::GooglePay:
            cout << "Processing GooglePay payment of $" << amount << endl;
            // Add GooglePay-specific logic here
            break;

        case PaymentMode::CreditCard:
            cout << "Processing Credit Card payment of $" << amount << endl;
            // Add Credit Card-specific logic here
            break;

        default:
            cout << "Invalid payment mode selected!" << endl;
            break;
    }
}

// Example usage
int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
```
#### Python Implementation
```
from enum import Enum

# Define Payment Modes
class PaymentMode(Enum):
    PAYPAL = 1
    GOOGLEPAY = 2
    CREDITCARD = 3
    UNKNOWN = 99

# Checkout function
def checkout(mode: PaymentMode, amount: float):
    match mode:
        case PaymentMode.PAYPAL:
            print(f"Processing PayPal payment of ${amount:.2f}")
            # Add PayPal-specific logic here

        case PaymentMode.GOOGLEPAY:
            print(f"Processing GooglePay payment of ${amount:.2f}")
            # Add GooglePay-specific logic here

        case PaymentMode.CREDITCARD:
            print(f"Processing Credit Card payment of ${amount:.2f}")
            # Add Credit Card-specific logic here

        case _:
            print("Invalid payment mode selected!")

# Example usage
if __name__ == "__main__":
    amount = 150.75

    checkout(PaymentMode.PAYPAL, amount)
    checkout(PaymentMode.GOOGLEPAY, amount)
    checkout(PaymentMode.CREDITCARD, amount)
    checkout(PaymentMode.UNKNOWN, amount)
```
#### C# Implentation
```
using System;

namespace PaymentProcessing
{
    // Enum for Payment Modes
    enum PaymentMode
    {
        PayPal,
        GooglePay,
        CreditCard,
        Unknown
    }

    class Program
    {
        // Checkout function
        static void Checkout(PaymentMode mode, double amount)
        {
            switch (mode)
            {
                case PaymentMode.PayPal:
                    Console.WriteLine($"Processing PayPal payment of ${amount:F2}");
                    // Add PayPal-specific logic here
                    break;

                case PaymentMode.GooglePay:
                    Console.WriteLine($"Processing GooglePay payment of ${amount:F2}");
                    // Add GooglePay-specific logic here
                    break;

                case PaymentMode.CreditCard:
                    Console.WriteLine($"Processing Credit Card payment of ${amount:F2}");
                    // Add Credit Card-specific logic here
                    break;

                default:
                    Console.WriteLine("Invalid payment mode selected!");
                    break;
            }
        }

        // Main program
        static void Main(string[] args)
        {
            double amount = 150.75;

            Checkout(PaymentMode.PayPal, amount);
            Checkout(PaymentMode.GooglePay, amount);
            Checkout(PaymentMode.CreditCard, amount);
            Checkout(PaymentMode.Unknown, amount);
        }
    }
}

```

#### Java Code
```
public class CheckoutDemo {

    // Enum for Payment Modes
    enum PaymentMode {
        PAYPAL,
        GOOGLEPAY,
        CREDITCARD,
        UNKNOWN
    }

    // Checkout function
    public static void checkout(PaymentMode mode, double amount) {
        switch (mode) {
            case PAYPAL:
                System.out.println("Processing PayPal payment of $" + String.format("%.2f", amount));
                // Add PayPal-specific logic here
                break;

            case GOOGLEPAY:
                System.out.println("Processing GooglePay payment of $" + String.format("%.2f", amount));
                // Add GooglePay-specific logic here
                break;

            case CREDITCARD:
                System.out.println("Processing Credit Card payment of $" + String.format("%.2f", amount));
                // Add Credit Card-specific logic here
                break;

            default:
                System.out.println("Invalid payment mode selected!");
                break;
        }
    }

    // Main program
    public static void main(String[] args) {
        double amount = 150.75;

        checkout(PaymentMode.PAYPAL, amount);
        checkout(PaymentMode.GOOGLEPAY, amount);
        checkout(PaymentMode.CREDITCARD, amount);
        checkout(PaymentMode.UNKNOWN, amount);
    }
}

```

#### C++ Payment code - review 

##1. Rigid Enum
     Adding a new payment mode requires editing both this enum and the switch in checkout. This violates the Open-Closed Principle (OCP) because the code is not open for extension but requires modification.

##2. Switch on enum
     switch with enums for behavior is called "switch envy". It spreads logic across many places and grows unmaintainable as cases increase.
   
##3. SRP violatiion
      Checkout knows how each payment works. Business logic is hardcoded here.

##4. Hardcoded strings
      Strings like "Processing PayPal..." are repeated per case. If format changes, multiple lines must be updated.

##5. Magic Number
      150.75 is a raw literal → not self-explanatory.
