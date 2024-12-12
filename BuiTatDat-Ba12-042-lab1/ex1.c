#include <stdio.h>

//Algorithm swap(num)
//if num <0 do
//  get num = -num;
//end if
//set n1 = num
//set first_digit = num
//set last_digt = num
//set count = 0
//set mul = 1
// while num != 0 do
//      increment count by 1
//      num = num /19
//End While
//Calculate power of 10
// For i = 0 to Count-1 do
//      mul = mul*10
//End For
//Get first digit
//While first_digit>10 do
//      first_digit=first_digit / 10
// End While 
//Get last_digit = last_digit mod 10
//get n2 = last_digit*mul +(n1*mul-last_digit)+first_digit;
//if(NumberNegative)do
//  n2 = -n2;
//End if
//return n2
//End Algorithm


//Function main
//Output "input number: "
//Input num
// n3 = swap(num)
//Output n3


int swap(int num){
    int n1,n2,first_digit,last_digit,count=0,mul=1;

    int NumNegative = num<0;
    if(NumNegative){
        num = -num;
    }
    n1 = num;
    first_digit = num;
    last_digit = num;
    
    while (num!=0)
    {
        count++;
        num/=10;
    }

    for (int i = 0; i < count-1; i++)
    {
        mul*=10;
    }
    

    while (first_digit>10)
    {
        first_digit/=10;
    }
    last_digit %=10;
    n2 = last_digit*mul+(n1%mul-last_digit)+first_digit;
    if(NumNegative){
        n2=-n2;
    }
    return n2;
    
    
}
int main(){
    int num;
    printf("input number: ");
    scanf("%d",&num);

    int n3 = swap(num);
    
    printf("%d",n3);
    
}
