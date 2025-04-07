// #include <stdio.h>
// int main()
// {
//     int n = 3, count = 0;

//     for (int i = n; i > 0; i--)
//     {
//         for (int k = i; k >= 0; k--)
//         {

//             printf("*\t");
//         }

//         if (count > 0)
//         {

//             for (i = 1; i < n - i; i++)
//             {

//                 printf(" \t");
//             }
//             for (i = 1; i < n - i; i++)
//             {

//                 printf(" \t");
//             }
//         }
//         for (int k = i; k >= 0; k--)
//         {

//             printf("*\t");
//         }

//         count++;
//         printf("\n");
//     }

//     return 0;
// }


#include <stdio.h>
int main()
{
    int n = 3; // Number of rows

    for (int i = 0; i < n; i++)
    {
        // Print stars on the left side
        for (int j = 0; j < n - i; j++)
        {
            printf("*\t");
        }

        // Print spaces in the middle
        for (int j = 0; j < 2 * i; j++)
        {
            printf(" \t");
        }

        // Print stars on the right side
        for (int j = 0; j < n - i; j++)
        {
            printf("*\t");
        }

        printf("\n");

    }

    return 0;
}
