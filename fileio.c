#include "fileio.h"

int readStudent(FILE *fp, Student *s) {
    if (fscanf(fp, "%s %s", s->id, s->name) != 2)
        return 0;

    for (int i = 0; i < SUBJECTS; i++) {
        fscanf(fp, "%s %d %d",
               s->subjects[i].subjectName,
               &s->subjects[i].minor,
               &s->subjects[i].major);
    }
    return 1;
}

void writeStudentTable(FILE *fp, const Student *s) {
    fprintf(fp,
        "%-8s %-10s "
        "%3d %2s  %3d %2s  %3d %2s  %3d %2s  %3d %2s  "
        "%4d %7.2f %5.2f  %s\n",

        s->id, s->name,

        s->subjects[0].total, s->subjects[0].grade,
        s->subjects[1].total, s->subjects[1].grade,
        s->subjects[2].total, s->subjects[2].grade,
        s->subjects[3].total, s->subjects[3].grade,
        s->subjects[4].total, s->subjects[4].grade,

        s->grandTotal,
        s->percentage,
        s->cgpa,
        s->finalGrade
    );
}
