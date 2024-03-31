#include <stdio.h>
#include "input_data.h"

const char *subject[]={"Engineering Physics","PSWC","Engineering Mathematics","Electrical","Mechanical"};

void Data_Input(char name[],float isa1m[],float isa2m[]) 
{
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter marks for ISA 1:\n");
    for (int i = 0; i < 5; i++) 
    { 
        printf("%s: ", subject[i]); 
        scanf("%f", &isa1m[i]);
        if(isa1m>40)
        {
            printf("Invalid marks entered");
            break;
        }
    }
    printf("Enter marks for ISA 2:\n");
    for (int i = 0; i < 5; i++) 
    { 
        printf("%s: ", subject[i]); 
        scanf("%f", &isa2m[i]);
        if(isa2m>40)
        {
            printf("\nInvalid marks entered\n");
            break;
        }
    }
}
float Calc(float marks[])
{
    float sum=0.00;
    float percentage;
    for(int i=0;i<5;i++)
    {
        sum+=marks[i];
    
    if (sum>200)
    {
        printf("\nInvalid\n");
        break;
    }
    }
    return percentage=(sum/200)*100;
}  

char Grade(float percentage)
{
    char grade;
    if (percentage >= 90) {
        grade = 'S';
    } else if (percentage >= 80) {
        grade = 'A';
    } else if (percentage >= 70) {
        grade = 'B';
    } else if (percentage >= 60) {
        grade = 'C';
    } else if (percentage >= 50) {
        grade = 'D';
    } else if (percentage >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }
    return grade;
}

void GradeCard(char name[], char grade1, char grade2) 
{
    printf("\n    Grade Card    \n");
    printf("Name: %s\n", name);
    printf("ISA 1 Grade: %c\n", grade1);
    printf("ISA 2 Grade: %c\n", grade2);

}

