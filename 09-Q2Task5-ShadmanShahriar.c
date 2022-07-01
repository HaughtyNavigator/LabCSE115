#include <stdio.h>
//This is a system to calculate very specific age, initials of names and average of CGPA using for loop and if else if.

int main() {
    
    int n, maleCount=0, femaleCount=0;
    char gender, name;
    float age, marks, cgpa, totalCGPA_female=0, totalMarks_male=0;
    n=1;
    
    //The code below  checks if the inputs are actually coinciding with the required conditions
    
    do{
        printf("Enter the age, marks, CGPA, name(first letter) and gender(F/M) of student %d\n", n);
        scanf("%f %f %f %c %c", &age, &marks, &cgpa, &name, &gender);
        
        if(gender == 'F' && name == 'N' && age >= 18 && age <= 28){
            totalCGPA_female = totalCGPA_female + cgpa;
            femaleCount += 1;
        }
        else if(gender == 'M' && name == 'H' && (age == 24 || age == 25 || age == 28)){
            totalMarks_male = totalMarks_male + marks;
            maleCount += 1;
        }
        n++;
    }
    while(n <= 10);
  
    //The code below verifies whether the value of total CGPA and total Marks are 0 or not in order to avoid garbage value in the output.
    
    if(totalCGPA_female > 0){
        float averageCGPA_female = totalCGPA_female / femaleCount;
        printf("Total CGPA of female students is %.2f and average CGPA is %.2f\n", totalCGPA_female, averageCGPA_female);
    }
    else{
        printf("No female student found according to the conditions.\n");
    }
    
    if(totalMarks_male > 0){
        float averageMarks_male = totalMarks_male / maleCount;
        printf("Total marks of male students is %.2f and average marks is %.2f\n", totalMarks_male, averageMarks_male);
    }
    else{
        printf("No male student found according to the conditions.\n");
    }
    
    
}



