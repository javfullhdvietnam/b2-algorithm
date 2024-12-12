#include <stdio.h>

//function main
//  get array[]={3,4,5,6,8,10,9,2,11}
// n = length of array
// for i = 0 to n do
//     for j = 0 to n do
//       for k = 0 to n do
//          if (arr[i]*arr[i]+arr[j]*arr[j]=arr[k]*arr[k])or(arr[k]*arr[k]+arr[i]*arr[i]=arr[j]*arr[j])or(arr[k]*arr[k]+arr[j]*arr[j]=arr[i]*arr[i]) then
//              output "(arr[i],arr[j],arr[k]) is a pythagorean triple"
//          else
//              output"arr[i],arr[j],arr[k] is not pythagorean triple"
//          end if
//          end for
//      end for
//   end for
//end function

int main(){
    int arr[]= {3,4,5,6,8,10,9,2,11};//1
    int n = sizeof(arr)/sizeof(arr[0]);//1

    int i,j,k;
    for (int i = 0; i < n; i++)//n
    {
       for (int j = 0; j < n; j++)//n
       {
        for (int k = 0; k< n; k++)//n
        {
            if (arr[i]*arr[i]+arr[j]*arr[j]==arr[k]*arr[k]||arr[k]*arr[k]+arr[i]*arr[i]==arr[j]*arr[j]||arr[k]*arr[k]+arr[j]*arr[j]==arr[i]*arr[i])
            {
                printf("\n(%d,%d,%d) is Pythagoream triple. ",arr[i],arr[j],arr[k]);
            }
            else
            {
                printf("\n(%d,%d,%d) is not a Pythagoream triple. ",arr[i],arr[j],arr[k]);
            }
            
            
        }
        
       }
       
    }
    
}

// timecomplexity 1 + 1 n^3 = O(n^3)