#include<stdio.h>

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


}

void deposit_money(){


}

void withdraw_money(){


}

void check_balance(){


}