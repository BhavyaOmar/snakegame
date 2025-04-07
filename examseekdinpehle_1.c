#include <stdio.h>

struct exm
{
    char name[30];
    int age;
    float per;
} emp1;

int main()
{

    FILE *gta = NULL;
    gta = fopen("test.txt", "a+");

    // char c = fgetc(gta);

    // printf("The very first char was \n %c", c);

    // c = fgetc(gta);

    // printf("The very first char was \n %c", c);

    // char part[3];

    // fgets(part, 5, gta);
    // printf("Apna string hai \n%s", part);

    fputc('j', gta);
    fputs("Inna saara kuch hai likhne ko but we have something...  metabutler and metasploit", gta);

    fclose(gta);
    return 0;
}