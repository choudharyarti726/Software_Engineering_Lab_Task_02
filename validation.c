#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

/* storing IDs to detect duplicates */
static char storedIds[100][15];
static int idCount = 0;

/* Roll number must contain letters and digits only,
   and must have at least one letter and one digit */
int validateStudentId(const char *id)
{
    int hasLetter = 0;
    int hasDigit = 0;

    for (int i = 0; id[i] != '\0'; i++) {

        if (isalpha(id[i]))
            hasLetter = 1;

        else if (isdigit(id[i]))
            hasDigit = 1;

        else
            return 0;   /* special character found */
    }

    if (hasLetter && hasDigit)
        return 1;

    return 0;
}

/* Name should contain only alphabets */
int validateName(const char *name)
{
    for (int i = 0; name[i] != '\0'; i++) {

        if (!isalpha(name[i]))
            return 0;
    }

    return 1;
}

/* Checking for duplicates Student Roll number */
int isDuplicateId(const char *id)
{
    for (int i = 0; i < idCount; i++) {

        if (strcmp(storedIds[i], id) == 0)
            return 1;
    }

    /* store new ID */
    strcpy(storedIds[idCount], id);
    idCount++;

    return 0;
}

/* Minor marks validation */
int validateMinor(int m)
{
    if (m >= 0 && m <= 40)
        return 1;

    return 0;
}

/* Major marks validation */
int validateMajor(int m)
{
    if (m >= 0 && m <= 60)
        return 1;

    return 0;
}
