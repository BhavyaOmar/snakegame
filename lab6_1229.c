#include <stdio.h>

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is greater than the root

    if (left < n && arr[left] > arr[largest])
        largest = left;

    // right child larger than the largest so far

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest not the root, swap

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
int main()
{
    // Understand and implement Heap sort.
    // Building a max heap from the input data.
    // Extracting the maximum element from the heap and placing it at the end of the array, then heapifying the remaining elements.

    int my_arr[] = {3, 19, 32, 27, 9, 5, 10};

    printf("Original array\n");
    for (int i = 0; i < 7; i++)
    {

        printf("%d ", my_arr[i]);
    }

    heapSort(my_arr, 7);

    printf("\nSorted array\n");
    for (int i = 0; i < 7; i++)
    {

        printf("%d ", my_arr[i]);
    }

    return 0;
}