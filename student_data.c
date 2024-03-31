#include <stdio.h>
#include "input_data.h"

const char *subject[]={"Engineering Physics","PSWC","Engineering Mathematics","Electrical","Mechanical"};

void Data_Input(char name[],float isa1m[],float isa2m[]) 
{
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter marks for exam 1:\n");
    for (int i = 0; i < 5; i++) 
    { 
        printf("%s: ", subject[i]); 
        scanf("%f", &isa1m[i]);
    }
    printf("Enter marks for exam 2:\n");
    for (int i = 0; i < 5; i++) 
    { 
        printf("%s: ", subject[i]); 
        scanf("%f", &isa2m[i]);
    }
}
float Average(float marks[])
{
    float sum=0.0;
    float avg;
    for(int i=0;i<5;i++)
    {
        sum+=marks[i];
    }
    return avg=sum/5;
}  

char Grade(float avg)
{
    char grade;
    if (avg >= 90) {
        grade = 'S';
    } else if (avg >= 80) {
        grade = 'A';
    } else if (avg >= 70) {
        grade = 'B';
    } else if (avg >= 60) {
        grade = 'C';
    } else if (avg >= 50) {
        grade = 'D';
    } else if (avg >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }
    return grade;
}

void GradeCard(char name[], char grade1, char grade2) 
{
    printf("\n===== Grade Card =====\n");
    printf("Name: %s\n", name);
    printf("Exam 1 Grade: %c\n", grade1);
    printf("Exam 2 Grade: %c\n", grade2);

}
