#include <stdio.h>
#include <string.h>
int main()
{

    char a[10], b[20];

    gets(a);
    gets(b);
    // fgets(b, 10, stdin);

    int c = strcmp(a, b);

    printf("%d", c);
    // puts(a);
    // puts(b);

    return 0;
}