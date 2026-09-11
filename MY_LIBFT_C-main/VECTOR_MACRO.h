#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h> 
#define DECLARE_VECTOR(type,name)\
typedef struct                   \
{                                \
    type  *arr;                  \
    size_t size;                 \
    size_t all_size;             \
}name;                           

#define VECTOR_PUSH_BACK(v,value) do {\
    if((v)->size == (v)->all_size)\
    {\
        (v)->all_size *= 2;\
        (v)->arr = (typeof((v)->arr))realloc((v)->arr,(v)->all_size * sizeof(*(v)->arr));\
    }\
    (v)->arr[(v)->size] = (value);\
    (v)->size++;\
}while(0)

#define DEFINE_INIT_FUNC(type,name,func_name)\
        static inline name func_name()\
        {\
        name my_v;\
        my_v.size = 0;\
        my_v.all_size = 2;\
        my_v.arr = (type *)malloc(my_v.all_size * sizeof(type));\
        return my_v;\
        }
DECLARE_VECTOR(int ,int_v)
DECLARE_VECTOR(char ,char_v)
DECLARE_VECTOR(float ,float_v)
DEFINE_INIT_FUNC(int ,int_v,init_int_vector)
DEFINE_INIT_FUNC(char ,char_v,init_char_vector)
DEFINE_INIT_FUNC(float ,float_v,init_float_vector)

#endif
