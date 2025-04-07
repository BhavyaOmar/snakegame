#include <stdio.h>
    int main(){
        int a = 23;
        float b = 56.46;

        printf("Float format of 56.46 is %f\n Int format of 56.46 is %d\n" , b ,(int)b );

        a = (int) b;
        
        printf("Float of a when a being 23 has been changed to int of 56.46 is %f\nWhile the int vaue of the same no. is %d", (float)a, a);


    return 0;
}