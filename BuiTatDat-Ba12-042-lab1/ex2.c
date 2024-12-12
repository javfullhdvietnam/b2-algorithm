#include <stdio.h>


int findMax(int *Max,int a){
    if(a> *Max){
        *Max = a;
    }
    else{
        *Max = 0;
    }
    return *Max;
}
int main(){
    int max = 0;
    int a;
    printf("input value of a number: ");
    scanf("%d",&a);

    int newMax=  findMax(&max, a);

    printf("max number is %d",newMax);
}