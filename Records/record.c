#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "../Types/struc.h"

void addrecord()
{
    system("cls");
    printf ("\n****** New Entry Details ******\n");
    time_t now;
    time (&now);
    struct tm *d = localtime (&now);    
    struct diary *rec = (struct diary *) malloc (sizeof (struct diary));

    rec->hr= d->tm_hour;
    rec->min= d->tm_min;    
    rec->day = d->tm_mday;
    rec->month = d->tm_mon + 1;
    rec->year = d->tm_year + 1900;
    if (rec->hr < 12)
        printf ("\nDate & Time: %02d/%02d/%d  %02d:%02d am", rec->day, rec->month, rec->year, rec->hr, rec->min);
    else
        printf ("\nDate & Time: %02d/%02d/%d  %02d:%02d pm", rec->day, rec->month, rec->year, rec->hr, rec->min);

    printf ("\n\nWhat's your mood ?\n");
    scanf ("%s", rec->mood);
    fflush (stdin);
    printf ("\nWhat's on your mind ?\n");
    gets (rec->info);
    rec->next = NULL;

    if (head == NULL)
        head = rec;
    else
    {
        while (head->next != NULL)
            head = head->next;
        
        head->next = rec;
    }
    printf ("\nRecord created..");
    Sleep (1000);
}

void viewrecord()
{
    system ("cls");
    if (head == NULL)
        printf ("\n---- No records to be displayed ----\n");
    else
    {
        struct diary *n = head;   
        int d, m, y, c = 0;
        printf ("****** Viewing Record ******\n");
        printf ("\nEnter the desired record's date (dd mm yyyy): ");
        scanf ("%d %d %d", &d, &m, &y);
        while (n != NULL)
        {
            if (n->day == d && n->month == m && n->year == y)
            {
                if (n->hr < 12)
                    printf ("\nTime of entry: %02d:%02d am", n->hr, n->min);
                else
                    printf ("\nTime of entry: %02d:%02d pm", n->hr, n->min);
                
                printf ("\n\nMood : %s", n->mood);
                printf ("\n\n%s\n\n---------------------\n", n->info);
                c++;
            }
            n = n->next;
        }
        if (c == 0)
            printf ("\n---- No records found for the entered date ----\n");
    }    
    printf ("\nPress any key to continue..");
    getch();
}