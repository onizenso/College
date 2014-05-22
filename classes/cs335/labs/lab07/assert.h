#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>

#define ASSERT(COND) { \
    if (!(COND)) {\
        fprintf(stderr, "Condition failed at line %d in %s\n", \
                __LINE__, __FILE__);\
    }\
} while (0)

#endif
