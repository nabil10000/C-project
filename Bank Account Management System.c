#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char address[100];
    char acc_type;
    float balance;
} Bank;

// Function prototypes
void open_account(Bank *customer);
void deposit_money(Bank *customer);
void withdraw_money(Bank *customer);
void display_account(Bank *customer);

int main() {
    Bank customer;
    int choice;

    do {
        printf("\n1) Open account \n"
               "2) Deposit money \n"
               "3) Withdraw money \n"
               "4) Display account \n"
               "5) Exit \n"
               "Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left in the input buffer

        switch (choice) {
        case 1:
            open_account(&customer);
            break;
        case 2:
            deposit_money(&customer);
            break;
        case 3:
            withdraw_money(&customer);
            break;
        case 4:
            display_account(&customer);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to open the account
void open_account(Bank *customer) {
    printf("Enter your full name: ");
    fgets(customer->name, sizeof(customer->name), stdin);
    customer->name[strcspn(customer->name, "\n")] = 0; // Remove newline character

    printf("Enter your address: ");
    fgets(customer->address, sizeof(customer->address), stdin);
    customer->address[strcspn(customer->address, "\n")] = 0; // Remove newline character

    printf("What type of account you want to open saving(S) or Current(C): ");
    scanf(" %c", &customer->acc_type);

    printf("Enter how much money you want to deposit: ");
    scanf("%f", &customer->balance);

    printf("Account Created Successfully\n");
}

// Function to deposit money into the account
void deposit_money(Bank *customer) {
    float amount;
    printf("Enter how much money you want to deposit: ");
    scanf("%f", &amount);
    customer->balance += amount;
    printf("Available Balance: %.2f\n", customer->balance);
}

// Function to withdraw money from the account
void withdraw_money(Bank *customer) {
    float amount;
    printf("Enter how much money you want to withdraw: ");
    scanf("%f", &amount);
    if (amount > customer->balance) {
        printf("Insufficient balance\n");
    } else {
        customer->balance -= amount;
        printf("Available Balance: %.2f\n", customer->balance);
    }
}

// Function to display account details
void display_account(Bank *customer) {
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Type: %s\n", (customer->acc_type == 'S' || customer->acc_type == 's') ? "Saving" : "Current");
    printf("Balance: %.2f\n", customer->balance);
}
