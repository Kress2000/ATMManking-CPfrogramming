#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //CHANGE SHEET COLOR!!!
    system("color 5F");

   int pin = 5555;
   int maxAmount =500000;
   double deposit;
   int option, enteredPin, count = 0, amount = 1;
   int continueTransaction = 1;
   float balance = 1000000;
   time_t now;
   time(&now);
   printf("\n");
   printf("\t\t\t\t %s", ctime(&now));
   printf("\n\t\t=============*Welcome to MERIC RESTAURENT*=============\n\n");
   //customer info asking:::
   while(pin != enteredPin){
    printf("\nEnter your pin number: ");
    scanf("%d", &enteredPin);
    count++;
    if(enteredPin != pin && count < 3){
        Beep(610, 500);
        printf("\nInvalid pin! Plz Insert a correct pin and continue\n");
    }
    if(enteredPin != pin && count == 3){
        Beep(610, 1000);
        printf("\nNumber of Trials exceeded!!\n");
        exit(0);

    }
   }
while(continueTransaction =! 0){

        //if pin is correct then what else!!!!
   printf("\n\t\t=============Available Transactions=============\n");
   printf("\t\t 1. Withdraw\n");
   printf("\t\t 2. Deposit\n");
   printf("\t\t 3. Check Balance\n");
   //customer selecting::::
   printf("\n\n\t\t Please Select the Option: ");
   scanf("%d", &option);

   switch(option){
   case 1:
        while(amount%500 != 0){
            printf("\n\n\t\t Enter amount to Withdraw:  ");
            scanf("%d", &amount);
            if(amount > maxAmount && amount < balance){
                printf("\n\n\t\t Can't exceed amount of 500 000Rwf on ATM!");
                amount = 1;

            }
            else if(amount > balance){
                printf("\n\n\t\t Insufficient fund!!\n");
            }
            else if(amount < 500){
                printf("\n\n\t\t Can't Withdraw amount less than 500Rwf on ATM!");
                amount = 1;
            }

        }

            balance -= amount;
            printf("\n\n\t\t Success!");
            printf("\n\n\t\t You have withdrawn amount: %dRwf successfully", amount);
            printf("\n\n\t\t And Your new Balance is %.2fRwf\n", balance);
            amount = 1;
            break;

   case 2:
       printf("\nEnter Amount you want to deposit: ");
       scanf("%lf", &deposit);
       balance += deposit;
       printf("\nYou have been successfully deposited %.2fRwf and now you have %.2fRwf on your account!\n", deposit, balance);
       printf("\nThank you for banking with us!!!\n\n");
       break;

   case 3:

       //customer showing that it's the owner of ac.-------
       while(pin != enteredPin){
            printf("\n\t\t Prove that it's you!");
            printf("\n\t\t Re-enter your Pin: ");
            scanf("%d", &enteredPin);
            count++;
            if(enteredPin != pin && count < 3){
                Beep(610, 500);
                printf("\nInvalid pin! Plz Insert a correct pin and continue\n");
            }
            if(enteredPin != pin && count == 3){
                Beep(610, 1000);
                printf("\nNumber of Trials exceeded!!\n");
                exit(0);
            }
       }

       printf("\n\n\t\t Your balance is %.2fRwf ", balance);
       break;

   default:
    Beap(610, 500);
    printf("Invalid choice!1");
    exit(0);
   }
//make transactions never end and the customer has a right to continue transacting!!!!
   printf("\n\n\t\t Do you want to continue Transactions? Press 1[Yes] 0[No]: ");
   scanf("%d", &continueTransaction);



}







return 0;
}
