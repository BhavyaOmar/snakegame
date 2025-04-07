#include <stdio.h>
#include <stdlib.h>
int main()
{

    // int a, b[10];

    // b = malloc(40);

    // scanf("%d", &a);

    // printf("Value of a is %d ", sizeof(b));

    int x = 10;
    float f = 2.5;

    f = (int)(x);

    printf("%f", f);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *a, b[10];

//     // Allocate memory for a single integer
//     a = (int *)malloc(sizeof(int));
//     if (a == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     // Input values
//     printf("Enter a value for a: ");
//     scanf("%d", a); // Store input in the allocated memory

//     printf("Enter 10 values for array b: ");
//     for (int i = 0; i < 10; i++)
//     {
//         scanf("%d", &b[i]);
//     }

//     // Output values
//     printf("Value of a is %d\n", *a); // Dereference pointer a
//     printf("Values in array b are: ");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d ", b[i]);
//     }
//     printf("\n");

//     // Free allocated memory
//     free(a);

//     return 0;
// }
