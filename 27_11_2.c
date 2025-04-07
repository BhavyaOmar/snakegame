#include <stdio.h>
    int main(){
        int a[5][5], b[5][5], s[5][5];

        printf("a ka samaan starts here :\n");
        for (int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                scanf("%d", &a[i][j]);
            }
        }

        printf("b ka samaan starts here :\n");
        for (int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                scanf("%d", &b[i][j]);
            }
        }

        for (int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                s[i][j] = a[i][j]+b[i][j];
            }
        }

        
        printf("s matrix ke tadanusaar darshan :\n");

        for(int i=0; i<5;i++ ){

            printf("\n");
            for(int j=0; j<5;j++){
                printf("\t%d", s[i][j]);
            }
        }

    return 0;
}