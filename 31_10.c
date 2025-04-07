#include <stdio.h>
    int main(){
        
        char test = '3';

        switch (test)
        {
        case '1':
            printf("One");
            break;

        case '2'||'3': printf("Two or Three");
            break;

        case '4':

            printf("Four");
            break;
        
        default:
            printf("Wrong Number");
            break;
        }


    return 0;
}