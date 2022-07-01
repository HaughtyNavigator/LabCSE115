#include <stdio.h>
//Below is a system to code a very specific number triangle
int main() {
    
    int a, n, x;
    int odd=1, even = 2;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    for (a=1; a<=n; a++){
        if(a%2==0){
            for(x=1; x<=a; x+=2){
                printf("%d ", even);
                even+=2;
            }
        }
        else{
            for(x=1; x<=a; x=x+2){
                printf("%d ", odd);
                odd+=2;
            }
        }
        printf("\n");
        odd=1;
        even = 2;
    }
    
    return 0;
}


