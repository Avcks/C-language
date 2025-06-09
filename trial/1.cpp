#include <stdio.h>
#include <string.h>

struct account {
    int acc_no;
    char name[100];
    float balance;
};

void create_account(struct account *acc);
void display_account(struct account acc);
void deposit(struct account *acc, float amount);
void withdraw(struct account *acc, float amount);

int main() {
    struct account acc;
    int choice;
    float amount;

    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(&acc);
                break;
            case 2:
                display_account(acc);
                break;
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc, amount);
                break;
            case 4:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc, amount);
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void create_account(struct account *acc) {
    printf("Enter account number: ");
    scanf("%d", &acc->acc_no);
    printf("Enter name: ");
    getchar(); 
    fgets(acc->name, 100, stdin);
    acc->name[strcspn(acc->name, "\n")] = '\0'; 
    acc->balance = 0;
    printf("Account created successfully.\n");
}

void display_account(struct account acc) {
    printf("\n--- Account Details ---\n");
    printf("Account No: %d\n", acc.acc_no);
    printf("Name: %s\n", acc.name);
    printf("Balance: ?%.2f\n", acc.balance);
}

void deposit(struct account *acc, float amount) {
    if (amount > 0) {
        acc->balance += amount;
        printf("?%.2f deposited successfully.\n", amount);
    } else {
        printf("Invalid amount.\n");
    }
}

void withdraw(struct account *acc, float amount) {
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("?%.2f withdrawn successfully.\n", amount);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}