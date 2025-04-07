#include <stdio.h>

int gcd(int a, int b ){
    int r = b%a;

    if (r==1){

        return 1;
    }

    else if(r == 0) {
         return a;
    }

    else {

        return gcd(r, a);
    }
    


}
int main()
{

    int a, b, r;

    printf("Enter the value of a and b :\n");

    scanf("%d %d", &a, &b);

    // while (r != 0)
    // {

    //     r = b % a;
    //     if (r != 0){

    //         b = a;
    //         a = r;

    //     }
    //     if (a == 1)
    //     {

    //         break;
    //     }
    // }


    printf("The GCD or HCF is %d", gcd(a,b));

    return 0;
}