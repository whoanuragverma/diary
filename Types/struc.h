struct diary
{
    char mood[20], info[5000];
    int day, month, year, hr, min;
    struct diary *next;
}*head = NULL;
