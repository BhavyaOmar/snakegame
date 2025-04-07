// // // #include <stdio.h>
// // // #include <math.h>
// // // int main()
// // // {
// // //     int n, a, b = 0, i = 1, d, sum = 0;

// // //     printf("Please enter the required number :\n");
// // //     scanf("%d", &n);

// // //     do
// // //     {

// // //         int k = pow(10, i);
// // //         a = n % k;
// // //         d = (a - b) / pow(10, i - 1);
// // //         sum += pow(d, 3);

// // //         b = a;
// // //         i++;

// // //     } while (d != 0);

// // //     printf("%d", sum);
// // //     return 0;
// // // }

// // #include <stdio.h>
// // #include <math.h>

// // int main() {
// //     int n, original, remainder, sum = 0;

// //     printf("Please enter the required number:\n");
// //     scanf("%d", &n);

// //     original = n;

// //     while (n != 0) {
// //         remainder = n % 10;
// //         sum += pow(remainder, 3);
// //         n /= 10;
// //     }

// //     if (sum == original) {
// //         printf("%d is an Armstrong number.\n", original);
// //     } else {
// //         printf("%d is not an Armstrong number.\n", original);
// //     }

// //     return 0;
// // }

// //

// // C Program to Display Armstrong
// // numbers between 1 to 1000
// #include <math.h>
// #include <stdio.h>

// int main()
// {
//     int i, sum,n, num, count = 0;
//     printf(
//         "Enter the value of n:\n");

//     scanf("%d", &n);

//     for (i = 1; i <=n; i++)
//     {
//         num = i;
//         // Count number of digits.
//         while (num != 0)
//         {
//             num /= 10;
//             count++;
//         }
//         num = i;
//         sum = pow(num % 10, count) + pow((num % 100 - num % 10) / 10, count) + pow((num % 1000 - num % 100) / 100, count);
//         // Check for Armstrong Number
//         if (sum == i)
//         {
//             printf("%d ", i);
//         }
//         count = 0;
//     }
// }

// // #include <stdio.h>
// // #include <math.h>
// // int main()
// // {
// //     int l, t = 0;

// //     printf("Please enter the number :\n");
// //     scanf("%d", &l);

// //     printf("2\n");
// //     for (int n = 3; n <= l; n++)
// //     {
// //         for (int i = 2; i <= sqrt(n); i++)
// //         {

// //             if (n % i == 0)
// //             {
// //                 t = 1;
// //                 break;
// //             }

// //             else {t = 0;}
// //         }

// //         if (t == 1)
// //         {
// //             printf("%d\n", n);
// //         }
// //     }

// //     return 0;
// // }

#include <stdio.h>
#include <math.h>

int countDigi(int num){

    int i=0;
    while (num!=0){

        num/=10;
        ++i;
    }

    return i;
}

// Checking for Armstrong...

int digiSum(int num){

    int sum = 0;

    int digiCount = countDigi(num);
}
int checkArms(int num){

    int originalNum, rem, n=0, res = 0;
    originalNum = num;

    while(originalNum != 0){

        rem = originalNum%10;
        int power=1;
        for(int i=0; i<n; i++){

            power*=rem;
        }

        res+=power;
        originalNum/=10;
    }

    if (res == num){

        return num;
    }
}
int main()
{

    int l,t = 0;
    printf("Please enter the number :\n");
    scanf("%d", &l);

    for(int p=2; p<=l ; p++){

        for(int i=2; i<=sqrt(p) ; i++){

            if (p%i ==0){

                t=1;
                break;
            }

        }

        if (t==0){

            printf("%d\n", checkArms(p));
        }
    }
    return 0;
}