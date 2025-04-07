#include <stdio.h>
    int main(){

        int a,b,r;

        printf("Enter first number :\n");
        scanf("%d", &a);
        printf("Enter second number :");
        scanf("%d", &b);      
      

        if(a==0 || b==0){

            printf("Invalid Entry");
        }
        else{

            while(r!=1){

                r=b%a;
                b=a;
                a=r;
            }}
        
    return 0;
}