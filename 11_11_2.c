#include <stdio.h>
int fibo(int a, int b, int n)
{

    if (n >= 0)
    {

        printf("%d", a);
        return fibo(b, a + b, n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the value of n :\n");
    scanf("%d", &n);
    printf("%d", fibo(0,1,n));
    return 0;
}