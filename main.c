#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX_STUDENTS 100

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    if (num_students > MAX_STUDENTS) {
        printf("Number of students exceeds limit (%d).\n", MAX_STUDENTS);
        return 1;
    }

    struct Student *students = (struct Student *)malloc(num_students * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        inputStudentData(&students[i]);
        generateGradeCard(&students[i]);
    }

    printf("\nReading all student data:\n");
    print_data();
    printf("\nReading specific student data:\n");
    char srn[MAX_SRN_LEN];
    printf("Enter SRN to search: ");
    scanf("%s", srn);
    print_student_result(srn);
    for (int i = 0; i < num_students; i++) {
        freeStudentData(&students[i]);
    }
    free(students);
    return 0;
}
