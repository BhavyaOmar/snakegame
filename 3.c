// #include <stdio.h>
//     int main(){
        
//         int len, bre;

//         printf("Enter length :");
//         scanf("%d", &len);

//         printf("Enter breadth :");
//         scanf("%d", &bre);

//         printf("The area of this rectangle is :%d",len*bre );

//     return 0;
// }

#include <stdio.h>
    int main(){
        
        int r;

        printf("Enter the radius : ");
        scanf("%d", &r);

        printf("Area of the circle with radius %d is %f.\n", r, 3.14*r*r);
        
        int h;
        printf("Enter the height for cylinder :");
        scanf("%d", &h);

        printf("Volume of cylinder with same radius and height %d is %f.", h, 3.14*r*r*h);

    return 0;
}