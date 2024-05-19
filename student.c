#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

char *subject_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};

void inputStudentData(struct Student *student) {
    printf("Enter the SRN of the student: ");
    scanf("%13s", student->SRN);

    printf("Enter student name: ");
    scanf("%s", student->name);

    student->num_subjects = MAX_SUBJECTS; 
    
    student->marks = (float *)malloc(student->num_subjects * sizeof(float));
    student->credits = (int *)malloc(student->num_subjects * sizeof(int));

    printf("Enter marks and credits for each subject:\n");
    for (int i = 0; i < student->num_subjects; i++) {
        printf("%s - Marks: ", subject_names[i]);
        scanf("%f", &student->marks[i]);
        printf("%s - Credits: ", subject_names[i]);
        scanf("%d", &student->credits[i]);
    }
}

float calculatePercentage(float *marks, int num_subjects) {
    float total_marks = 0.0;
    for (int i = 0; i < num_subjects; i++) {
        total_marks += marks[i];
    }
    return (total_marks / (num_subjects * 100)) * 100; 
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

float calculateSGPA(struct Student *student) {
    float total_credit_points = 0.0;
    int total_credits = 0;

    for (int i = 0; i < student->num_subjects; i++) {
        float percentage = (student->marks[i] / 100.0) * 100;
        int grade_points;

        if (percentage >= 90) {
            grade_points = 10;
        } else if (percentage >= 80) {
            grade_points = 9;
        } else if (percentage >= 70) {
            grade_points = 8;
        } else if (percentage >= 60) {
            grade_points = 7;
        } else if (percentage >= 50) {
            grade_points = 6;
        } else if (percentage >= 40) {
            grade_points = 5;
        } else {
            grade_points = 0;
        }

        total_credit_points += grade_points * student->credits[i];
        total_credits += student->credits[i];
    }

    return total_credits ? (total_credit_points / total_credits) : 0.0;
}

void generateGradeCard(struct Student *student) {
    FILE *file = fopen("details.csv", "a");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    fprintf(file, "%s,%s", student->SRN, student->name);

    float percentage = calculatePercentage(student->marks, student->num_subjects);
    float sgpa = calculateSGPA(student);

    printf("Grade Card for %s (%s):\n", student->name, student->SRN);
    printf("Subject\t\tMarks\tCredits\tGrade\n");
    for (int i = 0; i < student->num_subjects; i++) {
        char grade = calculateGrade((student->marks[i] / 100.0) * 100);
        printf("%s\t\t%.2f\t%d\t%c\n", subject_names[i], student->marks[i], student->credits[i], grade);
        fprintf(file, ",%.2f,%d,%c", student->marks[i], student->credits[i], grade);
    }

    printf("SGPA: %.2f\n", sgpa);
    fprintf(file, ",%.2f\n", sgpa);

    fclose(file);
}

void freeStudentData(struct Student *student) {
    free(student->marks);
    free(student->credits);
}

void print_data(void) {
    FILE *file = fopen("details.csv", "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token == NULL) continue;

        char SRN[15], name[50];
        strncpy(SRN, token, sizeof(SRN));
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(name, token, sizeof(name));

        printf("Grade Card for %s (%s):\n", name, SRN);
        printf("Subject\t\tMarks\tCredits\tGrade\n");

        for (int i = 0; i < MAX_SUBJECTS; i++) {
            float marks = atof(strtok(NULL, ","));
            int credits = atoi(strtok(NULL, ","));
            char grade = strtok(NULL, ",")[0];

            printf("%s\t\t%.2f\t%d\t%c\n", subject_names[i], marks, credits, grade);
        }

        float sgpa = atof(strtok(NULL, ","));
        printf("SGPA: %.2f\n", sgpa);
    }

    fclose(file);
}

void print_student_result(const char *srn) {
    FILE *file = fopen("details.csv", "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token == NULL) continue;

        if (strcmp(token, srn) == 0) {
            char SRN[15], name[50];
            strncpy(SRN, token, sizeof(SRN));
            token = strtok(NULL, ",");
            if (token == NULL) continue;
            strncpy(name, token, sizeof(name));

            printf("Grade Card for %s (%s):\n", name, SRN);
            printf("Subject\t\tMarks\tCredits\tGrade\n");

            for (int i = 0; i < MAX_SUBJECTS; i++) {
                float marks = atof(strtok(NULL, ","));
                int credits = atoi(strtok(NULL, ","));
                char grade = strtok(NULL, ",")[0];

                printf("%s\t\t%.2f\t%d\t%c\n", subject_names[i], marks, credits, grade);
            }

            float sgpa = atof(strtok(NULL, ","));
            printf("SGPA: %.2f\n", sgpa);
            fclose(file);
            return;
        }
    }

    printf("Student with SRN %s not found.\n", srn);
    fclose(file);
}

int main() {
    struct Student student;
    inputStudentData(&student);
    generateGradeCard(&student);
    freeStudentData(&student);

    printf("\nReading all student data:\n");
    print_data();

    printf("\nReading specific student data:\n");
    char srn[15];
    printf("Enter SRN to search: ");
    scanf("%s", srn);
    print_student_result(srn);

    return 0;
}
