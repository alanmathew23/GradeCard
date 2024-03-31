#include <stdio.h>
#include "input_data.h"
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

        float average_1=Average(isa1m);
        float average_2=Average(isa2m);

        char Grade_1=Grade(average_1);
        char Grade_2=Grade(average_2);

        GradeCard(name,Grade_1,Grade_2);
    }
    return 0;
}