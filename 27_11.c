#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
    int main(){
    //     int a[4];

    //     for (int i =0; i<4; i++){

    //         scanf("%d", (&a+ i*sizeof(int)));
    //         printf("%d\n", &a[i]);
    //     }

    //     printf("%d\n", sizeof(int));

    
    // printf("%d", a[1]);

    

    int a[6], i, n, c=0, flag=0;
    scanf("%d", &n);
    for(i=0; i<6; i++){
        scanf("%d", &a[i]);
    }
    // for(i=0; i<6; i++){
    //     if (n==a[i]){

    //         flag= 1;
    //         // printf("Found\n");
    //     }
    
    //     }



        // if (flag==1){

        //     printf("Aiyo Match Found !");
        // }

        // else{
        //     printf("Nothing to display");
        // }

        for (int i=0;i<5; i++){
            for(int j=0; j<5-i; j++){
                if (a[j]>a[j+1]){
                    a[j] = a[j]^a[j+1]^(a[j+1]=a[j]);
                }
            }
        }

    for(int i=0; i<6; i++ ){
            printf("[%d] = %d\n",i ,  a[i]);
        }
    return 0;
}