#include <stdio.h>
#include <math.h>

//Algorithm sphenic(n)
//get spec = 0
//For i = 2 to n do
//    get count = 0;
//    while n % i == 0 do
//      increment count by 1
//      get n = n / i
//    end while
//    if count == 1 do
//      increment by spec ++;
//    end if
//End for
//if spec == 3 do
//  return 1
//end if
//else do
//  return 0
//end else
//End Algorithm

//Function main
//  get n
//  output "input number: "
//  input n
//  if sphenic(n) =1 do
//      output "n is sphenic number "
// else do
//      output "n is not sphenic number "
// end if
//End Function

int sphenic(int n){

    
    int spec = 0;
    for (int i = 2; i<=n; i++){
        int count =0;
        while (n%i==0)
        {
            count++;
            n/=i;
        }

        if (count == 1)
        {
            spec++;
        }
        
    }
    if(spec == 3){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    int n;
    printf("input number: ");
    scanf("%d",&n);
   
    if(sphenic(n)==1){
        printf("%d is sphenic number",n);
    }
    else
    {
        printf("%d is not sphenic number",n);
    }
    

}