#include <stdio.h>
#include "input_data.h"
#include "student_data.c"
int main()
{
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++)
    {
        char name[50];
        float isa1m[5], isa2m[5];

        printf("Student %d:\n",i+1);
        Data_Input(name,isa1m,isa2m);

        float grade1=Calc(isa1m);
        float grade2=Calc(isa2m);

        char Grade_1=Grade(grade1);
        char Grade_2=Grade(grade2);

        GradeCard(name,Grade_1,Grade_2);
    }
    return 0;
}