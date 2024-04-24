#include <stdio.h>
#include <stdlib.h>
#include "student.h"

char *subject_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};

void inputStudentData(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter the number of subjects: ");
    scanf("%d", &student->num_subjects);

    // Dynamically allocate memory for marks
    student->marks = (float *)malloc(student->num_subjects * sizeof(float));

    printf("Enter marks for each subject:\n");
    for (int i = 0; i < student->num_subjects; i++) {
        printf("%s: ", subject_names[i]);
        scanf("%f", &student->marks[i]);
    }
}

float calculatePercentage(float *marks, int num_subjects) {
    float total_marks = 0.0;
    for (int i = 0; i < num_subjects; i++) {
        total_marks += marks[i];
    }
    return (total_marks / (num_subjects * 100)) * 100; // Calculate percentage
}

char calculateGrade(float percentage) {
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

void generateGradeCard(struct Student *student) {
    printf("Grade Card for %s:\n", student->name);

    float percentage = calculatePercentage(student->marks, student->num_subjects);
    if (percentage != -1) {
        printf("Percentage: %.2f%%\n", percentage);
        printf("Grade: %c\n", calculateGrade(percentage));
    } else {
        printf("Invalid total marks.\n");
    }
}

void freeStudentData(struct Student *student) {
    free(student->marks); // Free dynamically allocated memory
}
