#include <stdio.h>

int main()
{

    int a;
    // int b = 322;

    // a > b ? printf("a is greater than b") : printf("b is greater than a");
    
    printf("Enter a:");
    scanf("%d", &a);

    switch (a){

        case 1:
        printf("You entered 1\n");
        break;

        case 2:
        printf("You entered 2\n");
        break;

        case 3:
        printf("You entered 3\n");
        break;

        case 4:
        printf("You entered 4\n");
        break;

        default:
        printf("No number matched..\n");
    }
    
    
    return 0;
}
