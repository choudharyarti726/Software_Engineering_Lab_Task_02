#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include "student.h"

int readStudent(FILE *fp, Student *s);
void writeStudentTable(FILE *fp, const Student *s);

#endif

