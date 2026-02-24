#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account a[MAX];
    int count = 0;
    int choice, acc, found;
    float amount;

    while (1) {
        printf("\n=====================================\n");
        printf("       BANK MANAGEMENT SYSTEM        \n");
        printf("=====================================\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Balance Inquiry\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nEnter Account Number: ");
            scanf("%d", &a[count].accNo);

            printf("Enter Name: ");
            scanf("%s", a[count].name);

            printf("Enter Initial Balance: ");
            scanf("%f", &a[count].balance);

            count++;
            printf("\nAccount Created Successfully!\n");
            break;

        case 2:
            printf("\nEnter Account Number: ");
            scanf("%d", &acc);

            found = 0;
            for (int i = 0; i < count; i++) {
                if (a[i].accNo == acc) {
                    printf("Enter Deposit Amount: ");
                    scanf("%f", &amount);

                    a[i].balance += amount;
                    printf("\nAmount Deposited Successfully!\n");
                    found = 1;
                }
            }
            if (!found)
                printf("\nAccount Not Found!\n");
            break;

        case 3:
            printf("\nEnter Account Number: ");
            scanf("%d", &acc);

            found = 0;
            for (int i = 0; i < count; i++) {
                if (a[i].accNo == acc) {
                    printf("Enter Withdrawal Amount: ");
                    scanf("%f", &amount);

                    if (amount <= a[i].balance) {
                        a[i].balance -= amount;
                        printf("\nWithdrawal Successful!\n");
                    } else {
                        printf("\nInsufficient Balance!\n");
                    }
                    found = 1;
                }
            }
            if (!found)
                printf("\nAccount Not Found!\n");
            break;

        case 4:
            printf("\nEnter Account Number: ");
            scanf("%d", &acc);

            found = 0;
            for (int i = 0; i < count; i++) {
                if (a[i].accNo == acc) {
                    printf("\nAccount Holder: %s\n", a[i].name);
                    printf("Current Balance: %.2f\n", a[i].balance);
                    found = 1;
                }
            }
            if (!found)
                printf("\nAccount Not Found!\n");
            break;

        case 0:
            printf("\nExiting Program...\n");
            return 0;

        default:
            printf("\nInvalid Choice!\n");
        }
    }
}