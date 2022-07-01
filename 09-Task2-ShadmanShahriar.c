#include<stdio.h>
#include<math.h>
//Below is a system to find the sum of a very specific series
int main()
{
    int a,n,sum_even=0,sum_odd=0,sum=0;
    
    printf("Enter your value:");
    scanf("%d",&a);
    
    for(n=0; n<=a; n+=2){
        sum_even+= pow((a-n),2);
    }
    for(n=1; n<=a; n+=2){
        sum_odd+= pow((a-n),2);
    }
    sum=sum_even - sum_odd;
    
    printf("The sum is: %d\n",sum);
}

