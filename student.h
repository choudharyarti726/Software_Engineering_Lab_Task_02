#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 5

typedef struct {
    char subjectName[20];
    int minor;
    int major;
    int total;
    char grade[3];
} Subject;

typedef struct {
    char id[10];
    char name[20];
    Subject subjects[SUBJECTS];
    int grandTotal;
    float percentage;
    float cgpa;
    char finalGrade[3];
} Student;

#endif
