#include <stdio.h>
#include <time.h>
#include <conio.h>

int main()
{

    char c;

    for (int i = 0; i < 256; i++)
    {

        printf("%d ) \"%c\"\n\n", i, i);
    }
    int key = getch();

    if (key == 224)
    {
        key = getch();
        printf("Extended key code %d\n", key);
    }
}