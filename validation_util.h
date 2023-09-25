// validation_util.h

#ifndef VALIDATION_UTIL_H
#define VALIDATION_UTIL_H

int validateLength(const char *input, int maxLength);
int validateID(int id);
int validateName(const char *name);
int validateDate(int dd, int mm, int yy);

#endif

