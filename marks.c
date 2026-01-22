#include <string.h>
#include "marks.h"
#include "grade.h"

void calculateResult(Student *s) {
    s->grandTotal = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        s->subjects[i].total =
            s->subjects[i].minor + s->subjects[i].major;

        strcpy(s->subjects[i].grade,
               calculateGrade(s->subjects[i].total));

        s->grandTotal += s->subjects[i].total;
    }

    s->percentage = (float)s->grandTotal / SUBJECTS;
    s->cgpa = s->percentage / 10;

    strcpy(s->finalGrade,
           calculateFinalGrade(s->percentage));
}

