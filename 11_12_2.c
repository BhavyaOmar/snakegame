// // #include <stdio.h>

// // int main()
// // {
// //     char str[] = "Hellp";

// //     printf("%s", str);
// //     return 0;
// // }

#include <stdio.h>

int main()
{
    // char str[5] = {'H', 'e', 'l', 'l', 'o'}; // No null terminator
    // printf("String: %s\n", str); // Undefined behavior

    char a[10] = "Bhavya";
    char b[] = "Omar";

    int i, j;

    for (i = 0; a[i] != '\0'; i++)
        ;

    // i++;
    for (j = 0; b[j] != '\0'; j++, i++)
    {

        a[i] = b[j];
    }

    a[i] = '\0';

    printf("%s", a);

    return 0;
}

// #include <stdio.h>

// int main()
// {
//     char str1[50] = "Hello, ";
//     char str2[] = "World!";
//     int i, j;

//     // Finding the end of str1
//     for (i = 0; str1[i] != '\0'; i++)
//         ;

//     // Appending str2 to str1
//     for (j = 0; str2[j] != '\0'; j++, i++)
//     {
//         str1[i] = str2[j];
//     }

//     // Adding null terminator
//     str1[i] = '\0';

//     printf("Concatenated String: %s\n", str1);

//     return 0;
// }
