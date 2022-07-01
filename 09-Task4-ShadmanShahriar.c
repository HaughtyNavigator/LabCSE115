#include<stdio.h>
//Below is a code to print the fibonacci series easily upon input.For making it easy we firsthand printed 0 and 1.
int main()
{
    int n1=0,n2=1,n3,i,number;
    
    printf("Enter a number to count upto series:");
    scanf("%d",&number);
    
    printf("\n%d %d",n1,n2);
    
    for(i=2;i<number;++i)
    {
        n3=n1+n2;
        printf(" %d",n3);
        n1=n2;
        n2=n3;
    }

}

