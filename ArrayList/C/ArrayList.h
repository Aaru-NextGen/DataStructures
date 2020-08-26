// #include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int size;
    int capacity;
    int* array;
} ArrayList;

void push(ArrayList* simpleArray, int newVal);

void pop(ArrayList* simpleArray, int index);

void insert(ArrayList* simpleArray, int index, int value);

ArrayList slice(ArrayList* simpleArray, int from, int to, bool inplace);

ArrayList initArrayList();