#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

struct student
{
    int roll;
    struct student *next;
} s1, s2, s3;

typedef struct student stud;

void selectionSort() {}
int main()
{

    // int m, n;
    // scanf("%d %d", &m, &n);

    // swap(&m, &n);

    // printf("New values of m is %d and n is %d", m, n);
    // int *arr = (int *)malloc(n * sizeof(int));

    // printf("\nHence enter the elements in the array\n");
    // for (int i = 0; i < n; i++)
    // {

    //     scanf("%d", &arr[i]);
    // }

    // int a[] = {34, 2, 8, 29, 23, 4}

    stud *p;

    scanf("%d", &s1.roll);
    scanf("%d", &s3.roll);
    scanf("%d", &s2.roll);

    p = &s1;
    s1.next = &s2;
    s2.next = &s3;
    // Linear Search
    //  int p = 23;

    // for (int i = 0; i < 6; i++)
    // {
    //     if (a[i] == p)
    //     {
    //         printf("Found %d", p);
    //         printf("\n%d", a[i]);
    //         break;
    //     }
    // }

    return 0;
}