#include <stdio.h>
#include <string.h>
int main()
{
    int i = 1, c = 0;
    int temp;
    char a1[10];
    // gets(a);
    // int b = strlen(a);

    scanf("%s", a1);

    while (a1[i] != '\0')
    {
        i++;
    }

    int start = 0;
    int end = i-1;

    while (start < end)
    {
        temp = a1[start];
        a1[start] = a1[end];
        a1[end] = temp;

        // printf("%s", temp);
        start++;
        end--;
    }

    puts(a1);
    return 0;
}