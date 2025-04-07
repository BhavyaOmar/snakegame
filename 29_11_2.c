#include <stdio.h>
int main()
{
    int i = 0, flag = 0;
    char a[10], b[10];

    scanf("%s", a);
    scanf("%s", b);

    while (a[i] != '\0' && b[i] != '\0')
    {

        if (a[i] != b[i])
        {
            flag = 1;
            break;
        }
        i++;
    }

    if (flag == 1)
        printf("Not Equal");

    else
        printf("Equal");

    return 0;
}