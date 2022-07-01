#include <stdio.h>
 //Below is a code done to create a pyramid using stars, taking input as you like
int main()
{
   int r,c,n,temp;
 
   printf("Enter a number to print the pyramid accordingly:");
   scanf("%d",&n);
 
   temp = n;
 
   for (r=1; r<=n; r++)
   {
      for (c=1; c<temp; c++)
         printf(" ");
 
      temp--;
 
      for (c=1; c<=2*r-1; c++)
         printf("*");
 
      printf("\n");
   }

}

