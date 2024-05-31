#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and the size of strings
#define MAX_ACCOUNTS 100
#define NAME_SIZE 50
#define ADDRESS_SIZE 100
#define PASSWORD_SIZE 20

// Structure to represent a bank account
typedef struct {
    int account_number;
    char name[NAME_SIZE];
    char address[ADDRESS_SIZE];
    char password[PASSWORD_SIZE];
    float balance;
} Account;

// Global array to store accounts and a counter for the number of accounts
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Function prototypes
void create_account();
void login();
void deposit_money(int account_index);
void withdraw_money(int account_index);
void balance_inquiry(int account_index);
void change_password(int account_index);
void display_menu(int account_index);
int authenticate(const char *password, int account_index);

// Main function
int main() {
    int choice;

    do {
        printf("\nBank Account Management System\n");
        printf("1) Create account\n");
        printf("2) Login\n");
        printf("3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to create a new account
void create_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account new_account;
    new_account.account_number = num_accounts + 1;

    printf("Enter your full name: ");
    fgets(new_account.name, NAME_SIZE, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline character

    printf("Enter your address: ");
    fgets(new_account.address, ADDRESS_SIZE, stdin);
    new_account.address[strcspn(new_account.address, "\n")] = 0; // Remove newline character

    printf("Set your account password: ");
    fgets(new_account.password, PASSWORD_SIZE, stdin);
    new_account.password[strcspn(new_account.password, "\n")] = 0; // Remove newline character

    new_account.balance = 0.0f;

    accounts[num_accounts] = new_account;
    num_accounts++;

    printf("Account created successfully. Your account number is %d\n", new_account.account_number);
}

// Function to login to an existing account
void login() {
    int account_number;
    char password[PASSWORD_SIZE];

    printf("Enter your account number: ");
    scanf("%d", &account_number);
    getchar(); // Consume newline character

    if (account_number < 1 || account_number > num_accounts) {
        printf("Invalid account number.\n");
        return;
    }

    int account_index = account_number - 1;

    printf("Enter your password: ");
    fgets(password, PASSWORD_SIZE, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    if (authenticate(password, account_index)) {
        display_menu(account_index);
    } else {
        printf("Authentication failed.\n");
    }
}

// Function to authenticate user
int authenticate(const char *password, int account_index) {
    return strcmp(password, accounts[account_index].password) == 0;
}

// Function to deposit money into an account
void deposit_money(int account_index) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    accounts[account_index].balance += amount;
    printf("Deposit successful. New balance: %.2f\n", accounts[account_index].balance);
}

// Function to withdraw money from an account
void withdraw_money(int account_index) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    if (amount > accounts[account_index].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[account_index].balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", accounts[account_index].balance);
}

// Function to inquire account balance
void balance_inquiry(int account_index) {
    printf("Current balance: %.2f\n", accounts[account_index].balance);
}

// Function to change account password
void change_password(int account_index) {
    char new_password[PASSWORD_SIZE];

    printf("Enter new password: ");
    getchar(); // Consume newline character
    fgets(new_password, PASSWORD_SIZE, stdin);
    new_password[strcspn(new_password, "\n")] = 0; // Remove newline character

    strcpy(accounts[account_index].password, new_password);
    printf("Password changed successfully.\n");
}

// Function to display the account menu
void display_menu(int account_index) {
    int choice;

    do {
        printf("\nAccount Menu\n");
        printf("1) Deposit money\n");
        printf("2) Withdraw money\n");
        printf("3) Balance inquiry\n");
        printf("4) Change password\n");
        printf("5) Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit_money(account_index);
                break;
            case 2:
                withdraw_money(account_index);
                break;
            case 3:
                balance_inquiry(account_index);
                break;
            case 4:
                change_password(account_index);
                break;
            case 5:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
