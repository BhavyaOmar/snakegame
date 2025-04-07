#include <stdio.h>
#include <math.h>

    int main(){
        
        int a, b,c;
        float D = (b*b) - 4*a*c;
        if (a==0){

            printf("Invalid quadratic equation");

        }

        else{

            if (D > 0){

                printf("First solution of x is %f", (-b+sqrt(D)/(2*a)));

                printf("Second v solution of x is %f", (-b-sqrt(D)/(2*a)));
            }
            else if (D ==0){

            }
            else{

            }
        }

    return 0;
}