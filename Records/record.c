#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "../Types/struc.h"
#include "../auth/auth.h"

void addrecord(){
    FILE *fptr = fopen("records.dat","a+");
    system("cls");
    gotoxy(8,44);
    printf ("****** New Entry Details ******\n");
    time_t now;
    time (&now);
    struct tm *d = localtime (&now);    
    struct diary *rec = (struct diary *) malloc (sizeof (struct diary));
    rec->hr= d->tm_hour;
    rec->min= d->tm_min;    
    rec->day = d->tm_mday;
    rec->month = d->tm_mon + 1;
    rec->year = d->tm_year + 1900;
    gotoxy(2,44);
    if (rec->hr < 12)
        printf ("Date & Time: %02d/%02d/%d  %02d:%02d am", rec->day, rec->month, rec->year, rec->hr, rec->min);
    else
        printf ("Date & Time: %02d/%02d/%d  %02d:%02d pm", rec->day, rec->month, rec->year, rec->hr-12, rec->min);
    gotoxy(2,44);
    printf ("What's your mood ? ");
    scanf ("%s", rec->mood);
    fflush (stdin);
    gotoxy(1,44);
    printf ("What's on your mind ? \n");
    gotoxy(1,44);
    gets (rec->info);
    rec->next = NULL;
    fwrite(rec,sizeof(struct diary),1,fptr);
    gotoxy(1,44);
    printf ("Record created.");
    gotoxy(1,44);
    fclose(fptr);
    printf("Press any key to continue...");
    getch();
}

void viewrecord(){
    system ("cls");
    FILE *fptr = fopen("records.dat","r+");
    head = NULL;
    if(fptr!=NULL){
        while(1){
            struct diary *record = (struct diary*)malloc(sizeof(struct diary));
            fread(record,sizeof(struct diary),1,fptr);
            record->next = NULL;
            if(feof(fptr))
                break;
            if(head==NULL){
                head = record;
            }else{
                struct diary *n = head;
                while (n->next != NULL){
                    n = n->next;
                }
                n->next = record;
            }
        }
        fclose(fptr);
    }
    gotoxy(7,44);
    if (head == NULL)
        printf ("****** No records added yet ******");
    else
    {
        struct diary *n = head;   
        int d, m, y, c = 0;
        printf ("****** Viewing Record ******");
        gotoxy(2,35);
        printf ("Enter the desired record's date (dd mm yyyy): ");
        scanf ("%d %d %d", &d, &m, &y);
        while (n != NULL)
        {
            if (n->day == d && n->month == m && n->year == y)
            {
                gotoxy(1,46);
                if (n->hr < 12)
                    printf ("Time of entry: %02d:%02d am\n", n->hr, n->min);
                else
                    printf ("Time of entry: %02d:%02d pm\n", n->hr-12, n->min);
                gotoxy(0,50);
                printf ("Mood : %s\n", n->mood);
                gotoxy(0,35);
                printf ("You wrote: %s", n->info);
                gotoxy(2,44);
                printf("****** END of Record ******");
                c++;
            }

            n = n->next;
        }

        if (c == 0)
            printf ("**** No records found for the entered date ****");
    }    
    gotoxy(2,44);
    printf ("Press any key to continue..");
    getch();
}