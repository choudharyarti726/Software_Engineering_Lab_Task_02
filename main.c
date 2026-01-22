#include <stdio.h>
#include "student.h"
#include "validation.h"
#include "marks.h"
#include "fileio.h"
#include "statistics.h"
int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout) {
        printf("File open error\n");
        return 1;
    }

    int n;
    fscanf(fin, "%d", &n);
// Formatting for table header printing

    fprintf(fout, "ROLL_ID  NAME  " 
                  "     ALGO G  AOS  G  KRR  G  PSM  G  PDS  G "
                  " TOTAL PERCENT CGPA GRADE\n");

fprintf(fout,
    "-------------------------------------------------------------------------------------\n");
    Student s;
    ClassStats stats;

//calling the validation functions & rejecting bad input.
initStats(&stats);

    for (int i = 0; i < n; i++) {
        readStudent(fin, &s);
        if (!validateStudentId(s.id) ||
        isDuplicateId(s.id) || !validateName(s.name)) {
        continue;
}

        int valid = 1;
        for (int j = 0; j < SUBJECTS; j++) {
            if (!validateMinor(s.subjects[j].minor) ||
                !validateMajor(s.subjects[j].major)) {
                valid = 0;
                break;
            }
        }

        if (!valid)
           continue;

       // Calculate and printing Student Result

        calculateResult(&s);
        writeStudentTable(fout, &s);

        // updating class statistics
        updateStats(&stats, &s);
}

fprintf(fout,
    "======================================================================================\n");
// print class statistics summary

printStats(fout, &stats);
fclose(fin);
fclose(fout);
return 0;
}
