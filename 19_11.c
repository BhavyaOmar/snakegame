#include <stdio.h>
    int main(){
        int a,b,r;

        printf("Enter the value of a and b :\n");
        scanf("%d %d", &a, &b);
            do{
                r=b%a;
                b=a;
                a=r;
            }

            while(a!=0);
            
    
    printf("The HCF is %d", b);

    return 0;
}

// #include <stdio.h>
// int main() {
//     int a, b, r;

//     printf("Enter the values of a and b:\n");
//     scanf("%d %d", &a, &b);

//     while (b != 0) {  // Corrected condition to terminate when b becomes 0
//         r = a % b;    // Compute remainder of a divided by b
//         a = b;        // Update a to the value of b
//         b = r;        // Update b to the remainder
//     }

//     printf("The HCF is %d", a); // HCF will be stored in a
//     return 0;
// }
