#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdio.h>
#include "student.h"

typedef struct {
    float percentSum;
    float highest;
    float lowest;
    int count;

    int gradeO;
    int gradeA_plus;
    int gradeA;
    int gradeB_plus;
    int gradeB;
    int gradeC;
    int gradeD;
    int gradeF;
} ClassStats;

void initStats(ClassStats *cs);
void updateStats(ClassStats *cs, const Student *s);
float calculateClassAverage(const ClassStats *cs);
void printStats(FILE *fp, const ClassStats *cs);

#endif
