#include <stdio.h>
#include <string.h>
int main()
{

    char a[10], b[10];
    int i = 0;

    gets(a);
    while (a[i] != '\0')
    {

        b[i] = a[i];
        i++;
    }

    b[i] = '\0';
    puts(b);
    return 0;
}