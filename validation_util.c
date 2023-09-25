
// validation_util.c

#include "validation_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validateLength(const char *input, int maxLength) {
    return (strlen(input) <= maxLength);
}

int validateID(int id) {
    return (id > 0);
}

int validateName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) {
            return 0; // Name contains a digit
        }
    }
    return 1; // Name is valid
}

int validateDate(int dd, int mm, int yy) {
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yy < 1900) {
        return 0; // Invalid date
    }

    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) {
        return 0; // April, June, September, November have 30 days
    }

    if (mm == 2) {
        int isLeapYear = (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0));
        if ((isLeapYear && dd > 29) || (!isLeapYear && dd > 28)) {
            return 0; // February has 28 or 29 days
        }
    }

    return 1; // Date is valid
}
