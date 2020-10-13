struct diary
{
    char mood[10], info[5000];
    int day, month, year;
    struct diary *next;
}*head = nullptr;
