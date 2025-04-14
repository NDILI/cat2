#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_PIN_LENGTH 4 
#define MAX_ACCOUNTS 100

// Structure to represent a bank account
typedef struct {
    int accountNumber;
    char userName[MAX_NAME_LENGTH];
    char pin[MAX_PIN_LENGTH + 1]; // +1 for null terminator
    double balance;
} Account;

// Array to store account information
Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to generate a unique account number
int generateAccountNumber() {
    return 1000 + numAccounts;
}

// Function to create a new account
void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = generateAccountNumber();
    printf("Your new account number is: %d\n", newAccount.accountNumber);
    printf("Please enter preferred username (max %d characters): ", MAX_NAME_LENGTH - 1);
    fgets(newAccount.userName, sizeof(newAccount.userName), stdin);
    newAccount.userName[strcspn(newAccount.userName, "\n")] = 0;

    if (strlen(newAccount.userName) == 0) {
        printf("Error: Username cannot be empty.\n");
        return;
    }

    printf("Please enter a 4-digit PIN: ");
    fgets(newAccount.pin, sizeof(newAccount.pin), stdin);
    newAccount.pin[strcspn(newAccount.pin, "\n")] = 0;

    if (strlen(newAccount.pin) != MAX_PIN_LENGTH || strspn(newAccount.pin, "0123456789") != MAX_PIN_LENGTH) {
        printf("Error: PIN must be exactly 4 digits.\n");
        return;
    }

    newAccount.balance = 0.0;
    accounts[numAccounts++] = newAccount;
    printf("Account created successfully.\n");
}

// Function to find an account by account number
int findAccount(int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i; // Return the index of the account
        }
    }
    return -1; // Account not found
}

// Function to verify account number, username, and PIN
int verifyAccount(int accountNumber, const char *userName, const char *pin) {
    int accountIndex = findAccount(accountNumber);
    if (accountIndex == -1) {
        return -1; // Account not found
    }
    if (strcmp(accounts[accountIndex].userName, userName) != 0) {
        return -2; // Incorrect username
    }
    if (strcmp(accounts[accountIndex].pin, pin) != 0) {
        return -3; // Incorrect PIN
    }
    return accountIndex; // Account found and credentials verified
}

// Function to display balance
void displayBalance(int accountIndex) {
    printf("Your current balance is: Ksh%.2f\n", accounts[accountIndex].balance);
}

// Function to deposit money
void deposit(int accountIndex) {
    double amount;
    printf("Enter the amount to deposit: Ksh");
    scanf("%lf", &amount);
    getchar();

    if (amount > 0) {
        accounts[accountIndex].balance += amount;
        printf("Deposit successful. New balance: Ksh%.2f\n", accounts[accountIndex].balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

// Function to withdraw money
void withdraw(int accountIndex) {
    double amount;
    printf("Enter the amount to withdraw: Ksh");
    scanf("%lf", &amount);
    getchar();

    if (amount > 0) {
        if (accounts[accountIndex].balance >= amount) {
            accounts[accountIndex].balance -= amount;
            printf("Withdrawal successful. New balance: Ksh%.2f\n", accounts[accountIndex].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}



int main() {
    int choice;
    int accountNumber;
    char userName[MAX_NAME_LENGTH];
    char pin[MAX_PIN_LENGTH + 1];
    int accountIndex;
    char response[4];
    char printReceipt;

    printf("Welcome to the ATM Management System\n");
    printf("Do you have an account?\n");
    scanf("%3s", response);
    getchar();

    if (strcmp(response, "Yes") == 0 || strcmp(response, "yes") == 0) {
        printf("Please enter log in details\n");
        printf("Enter account number: ");
        scanf("%d", &accountNumber);
        getchar();
        printf("Enter username: ");
        fgets(userName, sizeof(userName), stdin);
        userName[strcspn(userName, "\n")] = 0;

        printf("Enter PIN: ");
        fgets(pin, sizeof(pin), stdin);
        pin[strcspn(pin, "\n")] = 0;

        accountIndex = verifyAccount(accountNumber, userName, pin);
        if (accountIndex == -1) {
            printf("Invalid credentials. Exiting.\n");
            return 0;
        } else if (accountIndex == -2) {
            printf("Incorrect username.\n");
            return 0;
        } else if (accountIndex == -3) {
            printf("Incorrect PIN.\n");
            return 0;
        } else {
            printf("Log in successful.\n");
        }
    } else if (strcmp(response, "No") == 0 || strcmp(response, "no") == 0) {
        printf("Do you want to create an account? (yes/no) ");
        scanf("%3s", response);
        getchar();
        if (strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
            createAccount();
            if (numAccounts > 0) {
                accountIndex = numAccounts - 1;
            } else {
                printf("Exiting the system.\n");
                return 0;
            }
        } else {
            printf("Access denied. Exiting.\n");
            return 0;
        }
    } else {
        printf("Invalid input. Exiting.\n");
        return 0;
    }

    do {
        printf("\nSelect an option:\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                displayBalance(accountIndex);
                break;
            case 2:
                withdraw(accountIndex);
                break;
            case 3:
                deposit(accountIndex);
                break;
            case 4: 
                printf("Thank you for using the ATM.\n");
                printf("Do you want to print a receipt? (y/n): ");
                scanf(" %c", &printReceipt);
                getchar();
                if (printReceipt == 'y' || printReceipt == 'Y') {
                    printf("\n--- Receipt ---\n");
                    printf("Account Number: %d\n", accounts[accountIndex].accountNumber);
                    printf("User Name: %s\n", accounts[accountIndex].userName);
                    printf("Current Balance: Ksh%.2f\n", accounts[accountIndex].balance);
                    printf("--- End of Receipt ---\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4); 

    return 0;
}
