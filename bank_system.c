#include<stdio.h>
#include<stdlib.h>

struct user_acc{
    int account_number;
    char name[30];
    float balance;
};

void user_menu();
void create_acc();
void deposit_money();
void withdraw_money();
void check_balance();


int main(){
    int option;
    while (1)
    {
    user_menu();
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        create_acc();
        break;
    case 2:
        deposit_money();
        break;
    case 3:
        withdraw_money();
        break;
    case 4:
        check_balance();
        break;
    case 5:
    printf("\nClosing the system. Thanks for visit!\n");
    return 0;
        break;
    default:
    printf("\nInvalid choice!\n");
        break;
    }
    }
}

void user_menu(){
    printf("\n\n*** Bank Management System ***");
    printf("\n1.Create Account");
    printf("\n2.Deposit Money");
    printf("\n3.Withdraw Money");
    printf("\n4.Check Balance");
    printf("\n5.Exit");
    printf("\nEnter your choice: ");
}

void create_acc(){
    FILE * file = fopen("account.dat","ab+");
    if (file == NULL){
        printf("Error opening file! ");
        exit(1);
    }

    struct user_acc acc;
    fflush(stdin);
    printf("Enter the name: ");
    scanf("%[^\n]s",&acc.name);

    printf("Enter account number: ");
    scanf("%d",&acc.account_number);
    acc.balance=0;
    fwrite(&acc,sizeof(acc),1,file);
    fclose(file);
    printf("Account registered successfully!");
}

void deposit_money(){
    FILE * file = fopen("account.dat","rb+");
    if (file == NULL){
        printf("Error opening file! ");
        exit(1);
    }
    struct user_acc acc;
    int acc_no;
    float money;
    printf("Enter account number in which you want to deposit your money: ");
    scanf("%d",&acc_no);
    printf("Enter amount to deposit: ");
    scanf("%f",&money);
    while(fread(&acc,sizeof(acc),1,file)){
        if (acc.account_number==acc_no){
            acc.balance += money;
            fseek(file,-sizeof(acc),SEEK_CUR);
            fwrite(&acc,sizeof(acc),1,file);
            print("\nSuccesfully deposited %.2f. New balance is %.2f.\n ",money,acc.balance);
            fclose(file);
            return;
        }
    
    printf("\nNo account with account number %d. Amount deposition failed! \n",acc_no);

}
}

void withdraw_money(){
    FILE * file = fopen("account.dat","rb+");
    if (file == NULL){
        printf("Error opening file! ");
        exit(1);
    }

}

void check_balance(){
     FILE * file = fopen("account.dat","rb");
    if (file == NULL){
        printf("Error opening file! ");
        exit(1);
    }
    int acc_no;
    printf("Enter account number: ");
    scanf("%d",&acc_no);
    struct user_acc acc;
    while(fread(&acc,sizeof(acc),1,file)){
        if (acc.account_number==acc_no){
            printf("\nYour account balance is %.2f.\n",acc.balance);
            fclose(file);
            return;
        }
    printf("\nNo account with account number %d.\n",acc_no);
    }
}