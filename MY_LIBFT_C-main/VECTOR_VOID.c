#include <stdio.h>
#include <stdlib.h> 
#include "VECTOR_VOID.h"
// بنية مصفوفة ديناميكية لتخزين وإدارة مؤشرات البيانات وحجمها الحالي والإجمالي في الذاكرة
void VECTOR_PUSH_BACK(name *v, void *value)
{
    if(v->size == v->all_size)
    {
        v->all_size *= 2;
        v->arr = (void**)realloc(
            v->arr,
            v->all_size * sizeof(void*)
        );
    }

    v->arr[v->size] = value;
    v->size++;
}

void VECTOR_POP_BACK(name *v)
{
    if(v->size > 0)
    {
        v->size--;
    }
}