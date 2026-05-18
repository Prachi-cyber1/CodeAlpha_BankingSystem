#include <stdio.h>
#include <stdlib.h>

// Structure for Bank Account
struct Account {

    int accNo;
    char name[50];
    float balance;
};

struct Account a;

// Function to Create Account
void createAccount() {

    FILE *fp;

    fp = fopen("accounts.txt", "a");

    printf("\nEnter Account Number: ");
    scanf("%d", &a.accNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fprintf(fp, "%d %s %.2f\n", a.accNo, a.name, a.balance);

    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

// Function to Display Accounts
void displayAccounts() {

    FILE *fp;

    fp = fopen("accounts.txt", "r");

    printf("\n===== Account Records =====\n");

    while(fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance) != EOF) {

        printf("\nAccount Number : %d", a.accNo);
        printf("\nName           : %s", a.name);
        printf("\nBalance        : %.2f\n", a.balance);
    }

    fclose(fp);
}

// Function to Deposit Money
void depositMoney() {

    FILE *fp, *temp;

    int accNumber, found = 0;
    float amount;

    fp = fopen("accounts.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNumber);

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    while(fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance) != EOF) {

        if(a.accNo == accNumber) {

            a.balance += amount;
            found = 1;

            printf("\nAmount Deposited Successfully!\n");
        }

        fprintf(temp, "%d %s %.2f\n", a.accNo, a.name, a.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if(found == 0) {
        printf("\nAccount Not Found!\n");
    }
}

// Function to Withdraw Money
void withdrawMoney() {

    FILE *fp, *temp;

    int accNumber, found = 0;
    float amount;

    fp = fopen("accounts.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNumber);

    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    while(fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance) != EOF) {

        if(a.accNo == accNumber) {

            found = 1;

            if(amount <= a.balance) {

                a.balance -= amount;

                printf("\nWithdrawal Successful!\n");

            } else {

                printf("\nInsufficient Balance!\n");
            }
        }

        fprintf(temp, "%d %s %.2f\n", a.accNo, a.name, a.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if(found == 0) {
        printf("\nAccount Not Found!\n");
    }
}

// Function to Check Balance
void checkBalance() {

    FILE *fp;

    int accNumber, found = 0;

    fp = fopen("accounts.txt", "r");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNumber);

    while(fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance) != EOF) {

        if(a.accNo == accNumber) {

            printf("\nAccount Found!\n");

            printf("Account Number : %d\n", a.accNo);
            printf("Name           : %s\n", a.name);
            printf("Balance        : %.2f\n", a.balance);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found == 0) {

        printf("\nAccount Not Found!\n");
    }
}

int main() {

    int choice;

    do {

        printf("\n===== Bank Management System =====\n");

        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Balance Enquiry\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                checkBalance();
                break;

            case 6:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    printf("\nThank You!\n");

    return 0;
}