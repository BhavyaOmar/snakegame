#include <stdio.h>
#include <string.h>
struct student
{
    char name[50];
    int roll;
    float marks;
} s[5];

int main()
{

    printf("Enter the record for 5 students:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nRecord for student %d\n", i + 1);

        printf("\nName :");
        // fgets(s[i].name, 50, stdin);

        // gets(s[i].name);
        scanf("%s", s[i].name);
        printf("\nRoll :");
        scanf("%d", &s[i].roll);
        printf("\nMarks :");
        scanf("%f", &s[i].marks);
    }

    return 0;
}