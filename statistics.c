#include <stdio.h>
#include <string.h>
#include "statistics.h"

void initStats(ClassStats *cs) {
    cs->percentSum = 0.0;
    cs->highest = -1.0;
    cs->lowest = 101.0;
    cs->count = 0;

    cs->gradeO = 0;
    cs->gradeA_plus = 0;
    cs->gradeA = 0;
    cs->gradeB_plus = 0;
    cs->gradeB = 0;
    cs->gradeC = 0;
    cs->gradeD = 0;
    cs->gradeF = 0;
}

void updateStats(ClassStats *cs, const Student *s) {

    cs->percentSum += s->percentage;
    cs->count++;

    if (s->percentage > cs->highest)
        cs->highest = s->percentage;

    if (s->percentage < cs->lowest)
        cs->lowest = s->percentage;

    /* STRING-BASED GRADE COMPARISON */
    if (strcmp(s->finalGrade, "O") == 0)
        cs->gradeO++;
    else if (strcmp(s->finalGrade, "A+") == 0)
        cs->gradeA_plus++;
    else if (strcmp(s->finalGrade, "A") == 0)
        cs->gradeA++;
    else if (strcmp(s->finalGrade, "B+") == 0)
        cs->gradeB_plus++;
    else if (strcmp(s->finalGrade, "B") == 0)
        cs->gradeB++;
    else if (strcmp(s->finalGrade, "C") == 0)
        cs->gradeC++;
    else if (strcmp(s->finalGrade, "D") == 0)
        cs->gradeD++;
    else
        cs->gradeF++;
}

float calculateClassAverage(const ClassStats *cs) {
    if (cs->count == 0)
        return 0.0;
    return cs->percentSum / cs->count;
}

void printStats(FILE *fp, const ClassStats *cs) {

    fprintf(fp, "Class Statistics\n");
    fprintf(fp, "-----------------------------\n");
    fprintf(fp, "Class Average Percentage : %.2f\n",
            calculateClassAverage(cs));
    fprintf(fp, "Highest Percentage       : %.2f\n", cs->highest);
    fprintf(fp, "Lowest Percentage        : %.2f\n", cs->lowest);

    fprintf(fp, "\nGrade Distribution\n");
    fprintf(fp, "O  Grade : %d\n", cs->gradeO);
    fprintf(fp, "A+ Grade : %d\n", cs->gradeA_plus);
    fprintf(fp, "A  Grade : %d\n", cs->gradeA);
    fprintf(fp, "B+ Grade : %d\n", cs->gradeB_plus);
    fprintf(fp, "B  Grade : %d\n", cs->gradeB);
    fprintf(fp, "C  Grade : %d\n", cs->gradeC);
    fprintf(fp, "D  Grade : %d\n", cs->gradeD);
    fprintf(fp, "F  Grade : %d\n", cs->gradeF);
}
