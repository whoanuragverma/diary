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
#include <windows.h>

int main(){
    if(isUserAvailable() == 0) signup();
    else login();
    
    int ch = 0;
    do
    {
        system ("cls");
        gotoxy(8,44);
        printf ("*****  Personal Diary Menu  *****");
        gotoxy(2,44);
        printf("1. Add new record");
        gotoxy(1,44);
        printf("2. View existing record");
        gotoxy(1,44);
        printf("3. Delete existing record");
        gotoxy(1,44);
        printf("4. Reset your password");
        gotoxy(1,44);
        printf("5. Logout");
        gotoxy(2,44);
        printf ("*********************************");
        gotoxy(2,44);
        printf ("What's your choice? ");
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
                deleterecord();
                break;
            case 4:
                resetpass();
                break;
            case 5:
                system ("cls");
                gotoxy (10, 48);
                printf ("***********************\n\n");
                gotoxy (1, 50);
                printf ("Logout Successful !\n\n");
                gotoxy (1, 48);
                printf ("***********************\n");
                exit(0);

            default: 
                gotoxy(1,45);
                printf ("Wrong choice. Please try again !\n");       
                Sleep (2000);            
        }
    }
    while (ch != 3);
}