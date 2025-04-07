#include <stdio.h>

// r, w, a, r+, w+, a+

struct Student
{

    char name[50];
    int roll;
};

typedef struct Student Stud;

int main()
{

    Stud s1 = {"Bhavya", 1229};

    FILE *file = fopen("test1.txt", "w");

    if (file == NULL)
    {

        printf("Error opening file\n");
        return 1;
    }

    // Writing in text format

    fprintf(file, "%s %d\n", s1.name, s1.roll);

    fclose(file);
    printf("Text file written successfully!\n");

    return 0;
}