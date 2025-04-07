#include <stdio.h>

// void swap (int *, int *);
// void swap(int &x, int &y){

// }



int main()
{
    // int a = 10, *b, **c;

    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a,&b);

    printf("%d %d", a, b);
    // b = &a;
    // c = &b;
    // // (**c)++;
    // printf("%d", b);

    return 0;
}

// void swap(int *a, int *b){

//     *a = *a + *b;
//     *b = *a - *b;
//     *a = *a - *b;

// }


// #include <stdio.h>

// void swap(int *, int *);

// int main() {
//     int a, b;
//     scanf("%d %d", &a, &b);  // Read values for a and b
//     swap(&a, &b);            // Pass the addresses of a and b to swap
//     printf("%d %d", a, b);   // Print swapped values
//     return 0;
// }

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
