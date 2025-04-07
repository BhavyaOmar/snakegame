#include <stdio.h>

void func(int *n)
{

    if (*n % 2 == 1)
    {

        *n = 5 * (*n);
    }
    else
    {

        *n = 2 * (*n);
    }
}

int main()
{
    int a;

    // b = a;
    // register int i;

    // for (i = 1; i < 10; i++)
    // {

    //     printf("%d\n", i);
    // }

    // for (i = 0; i < 5; i++)
    // {
    //     printf("%d\n", i);
    // }
    
    scanf("%d", &a);

    func(&a);
    // printf("%d\n", b);
    // printf("%d\n", &b);
    printf("%d\n", a);

    return 0;
}