#include <stdio.h>
#include <string.h>
int main()
{

    char a[10] = "Bhavya";
    char b[30] = "Omar";

    strcat(a, b);

    puts(a);
    puts(b);

    return 0;
}