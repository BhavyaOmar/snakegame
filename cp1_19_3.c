#include <stdio.h>
int main()
{

    char str[100];

    printf("Enter something :");
    scanf("%[^\n]", str);

    
    printf("%s", str);

    return 0;
}