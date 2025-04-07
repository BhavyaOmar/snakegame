#include <stdio.h>
int main()
{
    int n, inc = 0;

    printf("Please enter the value of n:\n");
    scanf("%d", &n);

    // for (int i = n; i >= 0; i--)
    // {

    //     for (int j = 1; j <= i; j++)
    //     {

    //         printf("*\t");
    //     }

    //     printf("\n");
    // }

    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {

            printf("*\t");
        }
        // for (int k = n - i; k >= 0; k--)
        // {

        //     printf(" \t");
        // }
        if (inc > 0)
        {
            for (int k = inc; k >= 0; k--)
            {

                printf(" \t");
            }
            for (int k = inc; k >= 0; k--)
            {

                printf(" \t");
            }
        }
        for (int j = 1; j <= i; j++)
        {

            printf("*\t");
        }

        for (int j = 0; j < i; j++)
        {

            printf("*\t");
        }

        printf("\n");
        inc++;
    }

    return 0;
}