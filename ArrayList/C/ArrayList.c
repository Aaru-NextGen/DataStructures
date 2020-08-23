#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    /* Create list of array based on the initial size provided or start with 2 */
    int size;
    int capacity;
    int* array;
} ArrayList;

void push(ArrayList* simpleArray, int newVal)
{
    int size = simpleArray->size;
    if (size == 0){
        simpleArray->capacity = 0;
    }
    int capacity = simpleArray->capacity;

    if (size == capacity)
    {
        int* newArr;
        if (capacity == 0 ){
            newArr = (int*)calloc(1, sizeof(int));  
            simpleArray->capacity = 1;
        } else {
            newArr = (int*)calloc(2*(capacity), sizeof(int));  
            simpleArray->capacity *= 2;
        }
             
        for (int i = 0; i < size; i++)
        {
            newArr[i] = simpleArray->array[i];
        }
        free(simpleArray->array);
        simpleArray->array = newArr;
    }
    simpleArray->array[size] = newVal;
    simpleArray->size += 1;
};


void pop(ArrayList* simpleArray, int index)
{

};

void popLast(ArrayList* simpleArray)
{

};

void insert(ArrayList* simpleArray, int index, int value)
{

};

ArrayList initArrayList()
{
    ArrayList array = {0};
    return array;
};

int main(){
    ArrayList simpleArray = initArrayList();
    for (int i = 0; i< 40; i++){
        push(&simpleArray, i);
        printf("capacity : %d, size : %d, value: %d\n", simpleArray.capacity, simpleArray.size, simpleArray.array[i]);
    }
    free(simpleArray.array);
    return 0;
}
