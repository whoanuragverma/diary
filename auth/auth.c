#include<stdio.h>
#include "../Types/user.h"
#include "../encryption/encryption.h"
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int a, int b)
{
    for (int i = 0; i < a; i++)    printf("\n");
    for (int i = 0; i < b; i++)    printf(" ");
}

int isUserAvailable()
{
    FILE *fileptr = fopen("user.dat","r+");
    if ( fileptr == NULL)   return 0;
    return 1;
}

char* inputpass(char *password, int index)
{
    char ch;
    while((ch = getch()) != 13)
    {
        if(index < 0)
            index = 0;           
        if(ch == 8)
        {
            if (index > 0)
            {
                putch('\b');
                putch((int)NULL);
                putch('\b');
                index--;
                continue;
            }
            else
                continue;            
        }               
        password[index++] = ch;
        putch('*');
    }
    password[index] = '\0';

    return password;
}

void login()
{
    int correct = -1, index;
    FILE *fileptr = fopen("user.dat", "r");
    struct user U;
    fread(&U, sizeof(struct user), 1, fileptr);
    fclose(fileptr);
    do
    {
        char password[20];
        system("cls");
        gotoxy(8, 44);
        if(correct == 0)   printf("INVALID PASSWORD - TRY AGAIN");
        gotoxy(1, 44);
        printf("********** User Login ***********");
        gotoxy(2, 44);
        printf("Hello %s,\n", U.username);
        gotoxy(0, 44);
        printf("Enter your password: ");
        strcpy(password, inputpass(password, index = 0));

        if(strcmp(U.password, encrypt(password)) == 0)   correct = 1; 
        else   correct = 0;
    }
    while(correct != 1);
}

void signup()
{
    char username[20], password[20], c;
    int index = 0;
    gotoxy(8, 44);
    printf("*****  User Registration  *****");
    gotoxy(2, 44);
    printf("Username: ");
    gets(username);
    gotoxy(0, 44);
    printf("Password: ");
    strcpy(password, inputpass(password, index));
    gotoxy(2,44);
    printf("*****  Sign Up Successful *****\n");
    struct user U;
    strcpy(U.username, username);
    strcpy(U.password, encrypt(password));
    FILE *fileptr = fopen("user.dat", "w");
    fwrite(&U, sizeof(struct user), 1, fileptr);
    fclose(fileptr);
    Sleep(2000);
    login();
}

void resetpass ()
{
    int correct = -1, index;
    FILE *fileptr = fopen("user.dat", "r");
    struct user U;
    fread(&U, sizeof(struct user), 1, fileptr);
    char uname[20];
    strcpy (uname, U.username);
    fclose(fileptr);
    do
    {
        char password[20], c;
        system("cls");
        gotoxy(8,48);
        if(correct == 0)   printf("INVALID PASSWORD - TRY AGAIN");

        gotoxy(1,44);
        printf("********* Password Reset **********");
        gotoxy(2,44);
        printf("Hello %s,\n", U.username);
        gotoxy(0,44);
        printf("Enter old password: ");
        strcpy(password, inputpass(password, index = 0));
        if(strcmp(U.password, encrypt(password)) == 0)   correct = 1;       
        else   correct = 0;           
    }
    while(correct != 1);
    char newpass[20], ch;
    FILE *fptr = fopen("user.dat","w");
    fread(&U, sizeof(struct user), 1, fptr);
    strcpy(U.username, uname);
    gotoxy(2, 44);
    printf("Enter new password: ");
    strcpy(newpass, inputpass(newpass, index = 0));
    strcpy(U.password, encrypt(newpass));
    fwrite(&U, sizeof(struct user), 1, fptr);
    fclose(fptr);
    gotoxy (2, 44);
    printf("*****  Password Changed Successfully *****\n");
    gotoxy (1, 48);
    printf("*****  Please Login Again *****\n");
    Sleep(2000);
    login ();    
}