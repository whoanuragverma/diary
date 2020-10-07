struct diary
{
    char mood[10];
    char month[10];
    int day;
    char text[100000];
    struct diary *next;
}*head = NULL;
