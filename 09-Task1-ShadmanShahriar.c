#include<stdio.h>
int main()
//The below is a code to find out how many people are within the age bracket of 40 to 60, with 40 and 60 being included.
{
    int n=1,age,person_count=0;
    
    while(n<=15){
        printf("Enter the age of person %d:",n);
        scanf("%d",&age);
        
        if(age>=40 && age <=60){
            person_count+=1;
            
        }
        n++;
        continue;
    }
    printf("The number of persons meeting the condition:%d\n",person_count);
}

