#include<stdio.h>
int main()
{
    int batch_num, password;
    
    printf("Enter your batch number:");
    scanf("%d",&batch_num);
    
    printf("Enter your password:");
    scanf("%d",&password);
    
    int div_by_4=password%4==0, div_by_6=password%6==0;
    
    switch(batch_num){
        case 153:
            switch(password){
                case 101 ... 599:
                    switch(div_by_4){
                        case 1:
                            printf("Login Successful!\n");
                            break;
                        default:
                            printf("Password must be divisible by 4!\n");
                    }
                    break;
                    default:
                        printf("Password must be from 101 to 599!\n");
            }
            break;
        case 221:
            switch(password){
                case 600 ... 999:
                    switch(div_by_6){
                        case 1:
                            printf("Login Successful!\n");
                            break;
                        default:
                            printf("Password must be divisible by 6!\n");
                    }
                    break;
                    default:
                        printf("Password must be from 600 to 999!\n");
            }
            break;
        default:
            printf("Batch number must be 153 or 221\n");
            
    }
        
}

