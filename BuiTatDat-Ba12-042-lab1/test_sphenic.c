#include <stdio.h>

void sphenic(int n){
    int count = 0;
    for (int i = 1; i <= n; i++){
        if(n%i==0){
            count++;
        
        }
    }
        printf("%d",count);
}

int main(){
    int n;
    scanf("%d", &n);
    sphenic(n);
    return 0;
}