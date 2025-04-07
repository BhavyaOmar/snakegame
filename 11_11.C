#include<stdio.h>

int  assignNew(int a, int b){

    int sum = a*10 + b;
    return sum;
}

int operation (int a){

    int newNum = 0, r=0, b;
    while (a!=0){

        r=a%10;
        newNum = assignNew(newNum, r);
        a/=10;
    }

    return newNum;
}

int main(){

    int x;
    scanf("%d" , &x);

    int newNum = operation(x);

    if (newNum == x){

        printf("\n Pallindrome\n");
    }

    else{

        printf("\n Not a pallindrome\n");
    }
}