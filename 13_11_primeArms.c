#include <stdio.h>
    int main(){
        
        // Time nahi hai abhi :(
        int sum =0;
        for (int i=1; i<=10; i++){

            (i%2!=0?sum+=i:0);

            
        }
        printf("%d", sum);

    return 0;
}