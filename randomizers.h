#ifndef RANDOMIZERS_H
#define RANDOMIZERS_H
#include <stdlib.h>

unsigned* random_(size_t size);
unsigned* reversed_sorted(size_t size);
unsigned* sorted(size_t size);
unsigned* unique_random(size_t size);
unsigned* almostsorted(size_t size);

#endif // #ifndef RANDOMIZERS_H