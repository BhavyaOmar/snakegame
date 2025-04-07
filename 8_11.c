#include <stdio.h>
#include <math.h>
int fact(int n)
{

    if (n == 1)
    {

        return 1;
    }

    else
    {

        return n * fact(n - 1);
    }
}

// int fibo(int a, int b, int n){

//     while (n !=0){

//         if (n==1){

//             return 0;
//     }

//         else{

//             printf("%d\n", a);
//             return fibo(b, a+b, n-1);
//     }

//     }
// }

// int sumf(int n)
// {
//     if (n == 0)
//     {

//         return 0;
//     }
//     return n % 10 + sumf(n / 10);
// }

// int digits(int a)
// {

//     if (a == 0)
//     {
//         return 0;
//     }
//     else
//     {

//         return 1 + digits(a / 10);
//     }
// }

int krishna(int a)
{

    // int digi = digits(a);
    //
    if (a == 0)
    {

        return 0;
    }

    else
    {

        return fact(a % 10) + krishna(a / 10);
    }
    // return
}

int main()
{

    int n;

    printf("Enter the value of n :\n");
    scanf("%d", &n);
    if (krishna(n) == n)
        {

            printf("%d is a Krihsnamurthy number...\n", n);
        }
    // printf("%d", fibo(0, 1, n));
    // printf("%d", arms(34, digits(34)));
    return 0;
}