#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LEN 50
#define MAX_SRN_LEN 15
#define MAX_SUBJECTS 5

struct Student {
    char name[MAX_NAME_LEN];
    char SRN[MAX_SRN_LEN];
    int num_subjects;
    float *marks;
    int *credits;
};

void inputStudentData(struct Student *student);
float calculatePercentage(float *marks, int num_subjects);
char calculateGrade(float percentage);
float calculateSGPA(struct Student *student);
void generateGradeCard(struct Student *student);
void freeStudentData(struct Student *student);
void print_data(void);
void print_student_result(const char *srn);

#endif 
