#include <stdio.h>

struct emp
{
    char name[30];
    int age;
    float bs;
};

int main()
{

    // FILE *fp;

    // struct employee;

    // fp = fopen("test.txt", "r");

    // if (fp == NULL)
    // {

    //     printf("File cannot be opened");
    //     // exit(1);
    // }
    // else
    // {

    //     printf("Hmm File exists..");
    //     // fclose(fp);
    // }

    // while (1)
    // {
    //     printf("\n 1 Add records");
    //     printf("\n Display");
    // }

    // switch (ch)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }
    auto int i = 10;
    {
        auto int i = 20;
        {
            auto int i = 30;
            printf("%d\n", i);
        }
        printf("%d\n", i);
    }
    printf("%d\n", i);

    extern int chukka = 20;

}