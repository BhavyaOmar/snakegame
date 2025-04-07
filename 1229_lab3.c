#include <stdio.h>
#include <stdlib.h>

// Write a program to call mergesort and quicksort functions for the same input array. Try analyze the program (any one function) with gdb.
void swap(int *a, int *b)
{

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void merge(int a[], int low, int mid, int high)
{
    int size = high - low + 1;

    int b[size], index = 0;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            b[index++] = a[left++];
        }
        else
        {
            b[index++] = a[right++];
        }
    }

    while (left <= mid)
    {

        b[index++] = a[left++];
    }
    while (right <= high)
    {
        b[index++] = a[right++];
    }

    for (int k = 0; k < size; k++)
    {

        a[low + k] = b[k];
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {

        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int a[], int i, int j)
{

    int p = a[i];
    int m = i;

    for (int k = i + 1; k <= j; k++)
    {

        if (a[k] < p)
        {
            m++;
            swap(&a[k], &a[m]);
        }
    }
    swap(&a[i], &a[m]);
    return m;
}

void quicksort(int a[], int low, int high)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = partition(a, low, high);
        quicksort(a, low, pivot_idx - 1);
        quicksort(a, pivot_idx + 1, high);
    }
}
int main()
{
    int *a;
    int size, task;

    // Size of array
    printf("Enter the size of array:\n");
    scanf("%d", &size);

    a = (int *)malloc(size * sizeof(int));

    printf("Please enter the elements for the array:\n");

    for (int o = 0; o < size; o++)
    {

        scanf("%d", &a[o]);
    }

    // Printing the array
    printf("Entered array : ");
    printf("[ ");
    for (int i = 0; i < size; i++)
    {

        printf("%d ", a[i]);
    }
    printf(" ]\n");

    printf("How do you want to sort?\nEnter 1 for merge sort and 2 for quick sort :\n");

    scanf("%d", &task);

    switch (task)
    {

    case 1:
        mergesort(a, 0, size - 1);
        printf("Successfully sorted using Merge Sort...\n");
        break;
    case 2:
        quicksort(a, 0, size - 1);
        printf("Successfully sorted using Merge Sort...\n");
        break;

    default:
        printf("Invalid Input");
    }

    // Sorted array
    printf("Sorted array : ");
    printf("[ ");
    for (int i = 0; i < size; i++)
    {

        printf("%d ", a[i]);
    }
    printf(" ]");

    return 0;
}