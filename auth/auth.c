#include<stdio.h>
#include "../Types/user.h"
#include "../encryption/encryption.h"
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int a, int b)
{
    for(int i = 0; i < a; i++)    printf("\n");
    for(int i = 0; i < b; i++)    printf(" ");
}

int isUserAvailable()
{
    FILE *fileptr = fopen("user.dat", "r+");
    if ( fileptr == NULL)
        return 0;
    return 1;
}

void login()
{
    int correct = -1;
    FILE *fileptr = fopen("user.dat","r");
    struct user U;
    fread(&U,sizeof(struct user),1,fileptr);
    do{
        char password[20], c;
        int index = 0;
        system("cls");
        gotoxy(8,44);
        if(correct == 0)
            printf("INVALID PASSWORD - TRY AGAIN");
        gotoxy(1, 44);
        printf("-----  User Login  -----");
        gotoxy(2, 44);
        printf("Hello %s,\n",U.username);
        gotoxy(0, 44);
        printf("Enter your password: ");
        while((c = getch()) != 13){
            if(index < 0)
                index = 0;
                if(c == 8){
                    putch('\b');
                    putch((int)NULL);
                    putch('\b');
                    index--;
                continue;
                }
            password[index++] = c;
            putch('*');
        }
        password[index] = '\0';        
        if(strcmp(U.password, encrypt(password)) == 0)   correct = 1;            
        else correct = 0;
    }
    while(correct != 1);
    gotoxy(2, 44);
    printf("CORRECT PASSWORD");
}

void signup()
{
    char username[20], password[20], c;
    int index = 0;
    gotoxy (8, 44);
    printf ("-----  User Registration  -----");
    gotoxy (2, 44);
    printf ("Username: ");
    gets (username);
    gotoxy (0, 44);
    printf ("Password: ");
    while ((c = getch()) != 13)
    {
        if(index < 0)
            index = 0;
        if(c == 8)
        {
            putch ('\b');
            putch ((int)NULL);
            putch ('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch ('*');
    }
    password[index] = '\0';
    gotoxy (2,44);
    printf ("-----  Sign Up Successfull -----\n");
    struct user U;
    strcpy (U.username, username);
    strcpy (U.password, encrypt (password));
    FILE *fileptr = fopen("user.dat", "w");
    fwrite (&U, sizeof(struct user), 1, fileptr);
    fclose (fileptr);
    Sleep (2000);
    login ();
}

