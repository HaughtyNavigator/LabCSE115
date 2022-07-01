#include<stdio.h>
int main()
{
    int batch_num, password;
    
    printf("Enter your batch number:");
    scanf("%d",&batch_num);
    
    printf("Enter your password:");
    scanf("%d",&password);
    
    
    if (batch_num==153)
    {
        if(password>=101 && password<=599){
            if(password%4==0){
                printf("Login Successful!\n");
            }
            else{
                printf("Password must be divisible by 4!\n");
            }
            
        }
        else{
            printf("Password range must be from 101 to 599!\n");
        }
        
    }
    else if (batch_num==221)
    {
        if(password>=600 && password<=999){
            if(password%6==0){
                printf("Login Successful!\n");
            }
            else{
                printf("Password must be divisible by 6!\n");
            }
            
        }
        else{
            printf("Password range must be from 600 to 999!\n");
        }
        
    }
    else{
        printf("Batch number must be 153 or 221!\n");
    }
    
        
}


