#ifndef SORTING_TEST_H
#define SORTING_TEST_H

#include <stddef.h>

void sorting_test(unsigned* (randomizer)(size_t), void (algorithm)(unsigned*, size_t), size_t *N, size_t size_N, const char *filename);

#endif // #ifndef SORTING_TEST_H