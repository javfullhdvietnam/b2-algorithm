#include <stdio.h>

int fsum(int n){
    int sum =0;
    int temp = n;
    while (temp>0)
    {  
        int d=temp%10;
        if(d!=0){
        sum +=d;
        
        }
        temp /=10;
    }
        return sum;
}

int recursion_sum(int n){
    if(n>0)
    return (n%10)+ recursion_sum(n/10);
}


int main(){
    int n = 303526;
    printf("%d",fsum(n));
    printf("\n%d",recursion_sum(n));

}