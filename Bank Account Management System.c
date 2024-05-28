#include <stdio.h>

typedef struct {
    double balance;
} Bank;

void deposit(Bank *bank) {
    double amount;
    printf("Enter amount to be deposited: ");
    scanf("%lf", &amount);
    bank->balance += amount;
    printf("\n Amount Deposited: %f\n", amount);
}

void withdraw(Bank *bank) {
    double amount;
    printf("Enter amount to be withdrawn: ");
    scanf("%lf", &amount);
    if (bank->balance >= amount) {
        bank->balance -= amount;
        printf("\n You Withdrew: %f\n", amount);
    } else {
        printf("\n Insufficient balance\n");
    }
}

void display(Bank *bank) {
    printf("\n Net Available Balance = %f\n", bank->balance);
}

int main() {
    Bank bank;
    bank.balance = 0.0;
    printf("Hello!!! Welcome to the Deposit & Withdrawal Machine\n");
    deposit(&bank);
    withdraw(&bank);
    display(&bank);
    return 0;
}

