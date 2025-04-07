//[1, 5, 7, 12]

// Case 1 : Right to left movement

//[12, 1, 5, 7] : First rotation

//[7, 12, 1, 5] : Second rotation

// Case 2 : Left to right movement

// [5, 7, 12, 1] : First rotation

// [7, 12, 1, 5] : Second rotation

#include <stdio.h>
int main()
{

    int a[4] = {7, 12, 1, 5};
    int b = a[0], c, d = a[0], e; // b is for smallest while d is for greatest element

    // c is index of smallest and e is index of the greatest element

    // First we would compare the elements and find the smallest as well as the greatest element

    for (int i = 0; i < 4; i++)
    {

        if (a[i] < b)
        {

            b = a[i];
            c = i;
            break;
        }
    }

    return 0;
}