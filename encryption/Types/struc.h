struct diary
{
    char mood[10], month[10], text[5000];
    int day, year;
    struct diary *next;
}*head = NULL;
