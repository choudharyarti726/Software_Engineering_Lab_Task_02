#include "grade.h"

const char* calculateGrade(int marks) {

    if (marks >= 90 && marks <= 100)
        return "O";
    else if (marks >= 85 && marks < 90)
        return "A+";
    else if (marks >= 75 && marks < 85)
        return "A";
    else if (marks >= 65 && marks < 75)
        return "B+";
    else if (marks >= 60 && marks < 65)
        return "B";
    else if (marks >= 55 && marks < 60)
        return "C";
    else if (marks >= 50 && marks < 55)
        return "D";
    else
        return "F";
}

const char* calculateFinalGrade(float p) {

    if (p >= 90.0 && p <= 100.0)
        return "O";
    else if (p >= 85.0 && p < 90.0)
        return "A+";
    else if (p >= 75.0 && p < 85.0)
        return "A";
    else if (p >= 65.0 && p < 75.0)
        return "B+";
    else if (p >= 60.0 && p < 65.0)
        return "B";
    else if (p >= 55.0 && p < 60.0)
        return "C";
    else if (p >= 50.0 && p < 55.0)
        return "D";
    else
        return "F";
}


