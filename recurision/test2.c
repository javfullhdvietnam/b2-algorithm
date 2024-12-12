#include <stdio.h>
#include <stdbool.h>

int is_sphenic(int n,int i,int spec){
    if(n==1&&spec==3)return true;
    if(n==1||i>n) return false;
    if (n%i==0)
    {
        int count = 0;
        while (n%i==0)
        {
           count++;
           n/=i;
        }
        if(count == 1){
            return is_sphenic(n,i+1,spec+1);
            }
            else{
                return false;
            }
    }
    return is_sphenic(n,i+1,spec);
}


int main(){
    int n = 244;
    for(int i =2;i<=n;i++){
        if(is_sphenic(i,2,0)){
            printf(" %d",i);
        }
    }
}