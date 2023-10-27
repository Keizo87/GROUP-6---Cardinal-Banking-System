#include <iostream>
#include <string>
#include "BankStackADT.h"
#include "BankStackType.h"

using namespace std;

const int NUM_ACCOUNTS = 5;

struct Account {
    string accountNumber;
    string accountName;
    double balance;
    string pin;
};

// Function to display a line of asterisks for design
void printLine() {
    cout << "**********************************************" << endl;
}

// Function to display a blank line for design
void printBlankLine() {
    cout << "*                                          *" << endl;
}

// Function to display a centered title with asterisks above and below
void displayTitle(const string &title) {
    const int titleLength = title.length();
    const int totalWidth = 50; // Total width of the title area
    const int borderWidth = (totalWidth - titleLength) / 2; // Calculate the border width on each side

    cout << string(totalWidth, '*') << endl; // Top border
    for (int i = 0; i < borderWidth; i++) {
        cout << '*'; // Left border
    }
    cout << ' ' << title << ' '; // Title text
    for (int i = 0; i < borderWidth; i++) {
        cout << '*'; // Right border
    }
    // If the title length is odd, add an extra '*' on the right
    if (titleLength % 2 != 0) {
        cout << '*';
    }
    cout << endl;
    cout << string(totalWidth, '*') << endl; // Bottom border
}


// Output #1:
void displayMainMenu() {
    displayTitle("Cardinal Banking System");
    cout << "                                \n";
    cout << "Press 'S' to start a transaction\n";
    cout << "                                \n";
    cout << "Press 'Q' to quit the program\n";  
    cout << "                                \n";
    cout << "Enter your choice: "; 
}

// Output #3: (Type of Transaction) for correct pin number
void displayTransactionMenu() {
  
  cout << "  Cardinal Banking System  \n";
  cout << "Press 'B' for Balance Inquiry\n";
  cout << "Press 'W' for Withdrawal\n";
  cout << "Press 'D' for Deposit\n";
  cout << "Press 'C' to Cancel\n";
  cout << "Enter your choice: ";
  
}

// Output #2: If S (Start Transaction)
bool isCorrectPIN(const string &enteredPin,
                  const string &correctPin) {
  return enteredPin == correctPin;
}

// Output #4: If B: (Balance Inquiry)
void balanceInquiry(const Account &account) {
  
  cout << "Cardinal Banking System\n";
  cout << "Balance Inquiry\n";
  cout << "Account Number: " << account.accountNumber << endl;
  cout << "Account Name: " << account.accountName << endl;
  cout << "Balance: " << account.balance << endl;
}

// Output #4: If W: (Withdrawal)
void withdraw(Account &account) {
  
  cout << "Cardinal Banking System\n";
  cout << "Withdrawal\n";
  cout << "Enter amount to be withdrawn: ";
  double amount;
  cin >> amount;

  if (amount >= 100 && (static_cast<int>(amount) % 100 == 0) &&
      (amount <= account.balance)) {
    account.balance -= amount;
    cout << "Withdrawal successful. Updated balance: " << account.balance
              << endl;
  } else {
    cout << "Invalid amount!\n";
    cout << "(must be in P100, P500, or P1000 bills)";
  }
}

// Output #4: If D: (Deposit)
void deposit(Account &account) {
  
  cout << "Cardinal Banking System\n";
  cout << "Deposit\n";
  cout << "Enter amount to be deposited: ";
  double amount;
  cin >> amount;

  if (amount >= 100 && (static_cast<int>(amount) % 100 == 0)) {
    account.balance += amount;
    cout << "Deposit successful. Updated balance: " << account.balance
              << endl;
  } else {
    cout << "Invalid amount!.\n";
    cout << "(must be in P100, P500, or P1000 bills)";
  }
}

// Output #5: View Customer Information
void viewAllDepositors(const Account accounts[NUM_ACCOUNTS]) {
  cout << "\nView All Depositors\n";
  for (int i = 0; i < NUM_ACCOUNTS; i++) {
    cout << "Account Number: " << accounts[i].accountNumber << "; ";
    cout << "Account Name: " << accounts[i].accountName << "; ";
    cout << "Balance: " << accounts[i].balance << endl;
  }
}

// Output #5: Add New Customer
void addNewCustomer(Account accounts[], int &numAccounts) {
  Account newCustomer;
  cout << "\nAdding a new customer\n";
  cout << "Enter Account Number: ";
  cin >> newCustomer.accountNumber;
  cout << "Enter Account Name: ";
  cin.ignore();
  getline(cin, newCustomer.accountName);
  cout << "Enter Initial Balance: ";
  cin >> newCustomer.balance;
  cout << "Enter PIN Number: ";
  cin >> newCustomer.pin;

  accounts[numAccounts++] = newCustomer;
  cout << "New customer added successfully.\n";
}

// Output #5: Edit Customer Information
void editCustomerInfo(Account accounts[], int numAccounts) {
  string accountNumber;
  cout << "\nEditing Customer Information\n";
  cout << "Enter the Account Number of the customer to edit: ";
  cin >> accountNumber;

  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accountNumber == accountNumber) {
      cout << "Enter New Account Name: ";
      cin.ignore();
      getline(cin, accounts[i].accountName);
      cout << "Enter New Balance: ";
      cin >> accounts[i].balance;
      cout << "Enter New PIN Number: ";
      cin >> accounts[i].pin;
      cout << "Customer information updated successfully.\n";
      return;
    }
  }

  cout << "Customer with the specified Account Number not found.\n";
}

// Output #5: Change Customer Pin Number
void changeCustomerPIN(Account accounts[], int numAccounts) {
  string accountNumber;
  cout << "\nChanging Customer's PIN Number\n";
  cout << "Enter the Account Number of the customer to change the PIN: ";
  cin >> accountNumber;

  for (int i = 0; i < numAccounts; i++) {
    if (accounts[i].accountNumber == accountNumber) {
      cout << "Enter New PIN Number: ";
      cin >> accounts[i].pin;
      cout << "Customer's PIN Number changed successfully.\n";
      return;
    }
  }

  cout << "Customer with the specified Account Number not found.\n";
}

// Administrator Operations
void handleAdministratorOperations(Account accounts[], int &numAccounts) {
  char choice;
  do {
  
    displayTitle("Administrator Menu");
    cout << "Press V to view all current depositors\n";
    cout << "Press A to add a new customer\n";
    cout << "Press E to edit customer information\n";
    cout << "Press C to change a customer's PIN number\n";
    cout << "Press X to terminate the program\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 'V':
    case 'v':
      viewAllDepositors(accounts);
      break;

    case 'A':
    case 'a':
      addNewCustomer(accounts, numAccounts);
      break;

    case 'E':
    case 'e':
      editCustomerInfo(accounts, numAccounts);
      break;

    case 'C':
    case 'c':
      changeCustomerPIN(accounts, numAccounts);
      break;

    case 'X':
    case 'x':
      return;

    default:
      cout << "Invalid key. Please enter a valid operation.\n";
    }
  } while (true);
}

// Customer Transactions
void handleCustomerTransactions(Account &customerAccount) {
  char choice;
  do {
    displayTransactionMenu();
    cin >> choice;

    switch (choice) {
    case 'B':
    case 'b':
      balanceInquiry(customerAccount);
      break;

    case 'W':
    case 'w':
      withdraw(customerAccount);
      break;

    case 'D':
    case 'd':
      deposit(customerAccount);
      break;

    case 'C':
    case 'c':
      return;

    default:
      cout << "Invalid key.\n";
      cout << "Please enter a valid transaction type.";
    }
  } while (true);
}

int main() {
  Account accounts[NUM_ACCOUNTS] = {

      {"0123-4567-8901", "Mr. Alburo", 5000.00, "1111"},
      {"2345-6789-0123", "Mr. Amores", 0.00, "2222"},
      {"3456-7890-1234", "Ms. Angeles", 10000.00, "3333"},
      {"4567-8901-2345", "Mr. Sasaki", 2500.00, "4444"},
      {"5678-9012-3456", "Mr. Cruz", 10000.00, "5555"}};
  int numAccounts = NUM_ACCOUNTS;

  char userChoice;
  do {
    displayMainMenu();
    cin >> userChoice;

    if (userChoice == 'Q' || userChoice == 'q') {
      cout << "Program terminated.\n";
      break;
    } else if (userChoice == 'S' || userChoice == 's') {
      string enteredPin;
      int attempts = 3;
      bool pinVerified = false;

      while (attempts > 0) {
        cout << "Enter your PIN: ";
        cin >> enteredPin;
        cout << "                   \n";

        if (isCorrectPIN(enteredPin, "0000")) {
          // Administrator login
          handleAdministratorOperations(accounts, numAccounts);
          break;
        } else {
          for (int i = 0; i < numAccounts; i++) {
            if (isCorrectPIN(enteredPin, accounts[i].pin)) {
              // Customer login
              handleCustomerTransactions(accounts[i]);
              pinVerified = true;
              break;
            }
          }
          if (pinVerified)
            break;

          attempts--;
          cout << "Invalid PIN. " << attempts << " attempts remaining.\n";
        }
      }

      if (attempts == 0) {
        cout << "CAPTURED CARD.... PLEASE CALL 143-44\n";
      }
    } else {
      cout << "Invalid choice. Please enter a valid option.\n";
    }

  } while (true);

  return 0;
}
