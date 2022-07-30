#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,r1,r2,c1,c2;
    
    printf("Enter the rows for 1st matrix:");
    scanf("%d",&r1);
    
    printf("Enter the columns for 1st matrix:");
    scanf("%d",&c1);
    
    printf("Enter the rows for 2nd matrix:");
    scanf("%d",&r2);
    
    printf("Enter the columns for 2nd matrix:");
    scanf("%d",&c2);
    
    
    int mat1[r1][c1];
    int mat2[r2][c2];
    int mat3[r1][c2];
    
    
    if(c1 != r2){
        printf("Error in dimensions!\n");
    }
    else{
        for(i=0; i<r1; i++){
            for(j=0; j<c1; j++){
                printf("Enter the elements of %d%d place matrix 1:",i,j);
                scanf("%d",&mat1[i][j]);
            }
            printf("\n");
        }
        
        for(i=0; i<r2; i++){
            for(j=0; j<c2; j++){
                printf("Enter the elements of %d%d place matrix 2:",i,j);
                scanf("%d",&mat2[i][j]);
            }
            printf("\n");
        }
        
        for(i=0; i<r1; i++){
            for(j=0; j<c2; j++){
                int sum=0;
                for(int k=0; k<c1; k++){
                    sum+= mat1[i][k]*mat2[k][j];
                    mat3[i][j]=sum;
                }
            }
        }
        printf("The result of the multiplicaton is:\n");
        for(i=0; i<r1; i++){
            for(j=0; j<c2; j++){
                printf("%10d",mat3[i][j]);
            }
            printf("\n");
        }
    }
    
}

