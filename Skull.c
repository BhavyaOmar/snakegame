#include <stdio.h>
#include <string.h>

struct zinga
{

    char name[30];
    int age;
    int salary;
} me, you, they, stud[5];
int main()
{

    // strcpy(me.name, "Bhavya Omar");
    // printf("Hello hello, %d here !", me.age);

    for (int i = 0; i < 100; i++)
    {

        printf("Record for student %d\n", i + 1);

        printf("Name :");
        scanf("%s", stud[i].name);
    }

    return 0;
}