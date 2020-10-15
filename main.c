/**
 * 
 * Project structure is going to look something like this.
 * Make sure you have your code defragmented into smaller bits for easier integration and testing. 
 * 
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include "auth/auth.h"
#include "Records/record.h"
#include <time.h>


int main(){
    if(isUserAvailable() == 0) signup();
    else login();

    int ch = 0;
    do
    {
        system ("cls");
        printf ("***** Personal Diary Menu *****\n1. Add new record\n2. View existing record\n3. Logout\n");
        printf ("\n*****************************\n");
        printf ("\nWhat's your choice?\n");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1:
                addrecord();
                break;
            case 2:
                viewrecord();
                break;
            case 3:
                system ("cls");
                printf ("Logout Successful !");
                exit(0);
            default: printf ("\nWrong choice. Please try again !\n");                   
        }
    }
    while (ch != 3);
}