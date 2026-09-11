#ifndef VECTOR_VOID
#define VECTOR_VOID
#include <stddef.h>

typedef struct
{
    void **arr;
    size_t size;
    size_t all_size;
} name;

void VECTOR_PUSH_BACK(name *v, void *value);
void VECTOR_POP_BACK(name *v);

#endif