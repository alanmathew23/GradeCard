#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[50];
    int num_subjects;
    float *marks;
};

void inputStudentData(struct Student *student);
void generateGradeCard(struct Student *student);

#endif
