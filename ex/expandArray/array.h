/**
 * @author      : binsu (binsu@binsu.c.googlers.com)
 * @file        : array
 * @created     : Friday Aug 28, 2020 02:04:27 PDT
 */

#ifndef ARRAY_H

#define ARRAY_H

typedef struct{
  int *array;
  int size;
} Array;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);


#endif /* end of include guard ARRAY_H */

