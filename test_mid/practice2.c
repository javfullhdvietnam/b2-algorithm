#include <stdio.h>

int main(){
   double num1 = 4.47;
   int num2 = num1;
   int num4 = num1;
   int remider[40];
   int i=0;
   while (num2>0)
   {
    remider[i] = num2%2;
    num2 =num2/2;
    i++;
   }

   int reverse_num[40];
   for(int j=i-1;j>=0;j--){
        reverse_num[j]=remider[j];
    printf("%d",reverse_num[j]);
   }

    double num3 = num1-num4;

    int integal[40];

    printf("\n");
    for(int i=0;i<num4;i++){
        num3=num3*2;
        if(num3>=1){
            integal[i]=1;
        }
        else{
            integal[i]=0;
        }
        printf("%d",integal[i]);
    }
}