// Write a program to store student information in an array of structure "stud". Write functions 1. Delete one student info. 2.Add one student info. The structure should be sorted.

// In the program, I have not assigned any student with any info. User is supposed to manually add a particular info and hence delete it if required.
// lab1_regno.c

#include <stdio.h>
#include <string.h>

// To tackle errors with string hadling, I have used strcmp for string comparison and strcpy to assign a value to our string in our program

struct student
{

    char name[30];
    int age;
    int roll;
} stud[5]; // We predefined an array (with length 5) of structure "stud"

// To match my program logic, preassigning the stud elements with some values
void assignVals()
{
    for (int i = 0; i < 5; i++)
    {
        strcpy(stud[i].name, "0");
        stud[i].age = 0;
        stud[i].roll = 0;
    }
}

// Function to delete an info
void delInfo(int studNum)
{
    int c;
    printf("Enter 1 to delete the name, 2 to delete the age, and 3 to delete the roll number\n");
    scanf("%d", &c);

    switch (c)
    {

        // We first check if there is any value other than our predefined values, if yes we delete it, if no we display to let user know that no data has been entered here yet
    case 1:
        if (stud[studNum].name != "0")
        {
            strcpy(stud[studNum].name, "0");
            printf("Data deleted successfully \n");
        }
        else
        {
            printf("Data already does not exist !!!\n");
        }
        break;

    case 2:
        if (stud[studNum].age != 0)
        {
            stud[studNum].age = 0;
            printf("Data deleted successfully \n");
        }
        else
        {
            printf("Data already does not exist !!!\n");
        }
        break;

    case 3:
        if (stud[studNum].roll != 0)
        {
            stud[studNum].roll = 0;
            printf("Data deleted successfully \n");
        }
        else
        {
            printf("Data already does not exist !!!\n");
        }
        break;
    }
}

// Function to add an info
void addInfo(int studNum)
{
    int c;
    printf("Enter 1 to add the name, 2 to add the age, and 3 to add the roll number \n");
    scanf("%d", &c);

    switch (c)
    {
        // In order to add a data, the existing value must be equal to what we had assigned in our assignVals function.
        // Else we would warn the user that the given field already contains some data and let user know what is the value. A user must delete the data to assign a new value. This is to insure that the user is aware of the preexisting values
    case 1:
        if (strcmp(stud[studNum].name, "0") != 0)
        {
            printf("Data already exists! Please delete it first to add a new data...\n");
            printf("Current Data :%s\n", stud[studNum].name);
        }
        else
        {

            printf("Enter the name :\n");
            scanf("%s", stud[studNum].name);
        }
        break;

    case 2:
        if (stud[studNum].age != 0)
        {
            printf("Data already exists! Please delete it first to add a new data...\n");
            printf("Current Data :%d\n", stud[studNum].age);
        }
        else
        {

            printf("Enter the age :\n");
            scanf("%d", &stud[studNum].age);
        }
        break;

    case 3:
        if (stud[studNum].roll != 0)
        {
            printf("Data already exists! Please delete it first to add a new data...\n");
            printf("Current Data :%d\n", stud[studNum].roll);
        }
        else
        {

            printf("Enter the roll number :\n");
            scanf("%d", &stud[studNum].roll);
        }
        break;
    }
}

int main()
{
    int a, b, m = 1; // m has been defined to run an infinite while loop
    assignVals();    // Preassigning default values to all the elements of our structure

    while (m == 1)
    {
        printf("*****       Please enter '404' to exit        *****\n\n\n");

        printf("Enter the student number whose details you want to modify (Only student number 1 to 5 are permissible):\n");
        scanf("%d", &a); // a is to store the student number

        // student numbers start from 1 but indexing starts from 0 hence to adjust our index with student number, we did a-1 before putting this value in our add or delete functions

        if (a <= 5 && a > 0)
        {

            printf("Enter 0 to delete a data or 1 to edit a data\n");
            scanf("%d", &b);

            if (b == 0)
            {
                // From here the command goes on to our delInfo function
                delInfo(a - 1);
            }

            else if (b == 1)
            {
                // From here the command goes on to our addInfo function
                addInfo(a - 1);
            }

            else if (b == 404)
            {
                break;
            }

            else
            {
                printf("Invalild Input\n");
            }
        }

        else if (a == 404) // User could enter 404 and the infinite loop will break
        {

            break;
        }

        else // To avoid the unwanted iteration bug of loop on entering an invalid value in our current program, loop will break displaying message to enter a valid number
        {

            printf("Enter a valid number !!!\n");
            break;
        }
    }

    return 0;
}