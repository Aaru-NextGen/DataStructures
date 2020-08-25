#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Create list of array based on the initial size provided or start with 2 */
typedef struct {
    int size;
    int capacity;
    int* array;
} ArrayList;


void checkAndDoubleSize(ArrayList* simpleArray){
    if (simpleArray->size == simpleArray->capacity){
        int* newArr;
        if (simpleArray->capacity == 0 ){
            newArr = (int*)calloc(1, sizeof(int));  
            simpleArray->capacity = 1;
        } else {
            newArr = (int*)calloc(2*(simpleArray->capacity), sizeof(int));  
            simpleArray->capacity *= 2;
        }
             
        for (int i = 0; i < simpleArray->size; i++){
            newArr[i] = simpleArray->array[i];
        }
        free(simpleArray->array);
        simpleArray->array = newArr;
    }
}

void checkAndQuench(ArrayList* simpleArray){
    if (simpleArray->size < simpleArray->capacity/4-4){
        int* newArray;
        newArray = (int*)calloc(simpleArray->capacity/4, sizeof(int));
        simpleArray->capacity = simpleArray->capacity/4;

        for (int i = 0; i < simpleArray->size; i++){
         newArray[i] = simpleArray->array[i];
        }

        free(simpleArray->array);
        simpleArray->array = newArray;
    }
}

void push(ArrayList* simpleArray, int newVal){
    if (simpleArray->size == 0){
        simpleArray->capacity = 0;
    }
    checkAndDoubleSize(simpleArray);
    simpleArray->array[simpleArray->size] = newVal;
    simpleArray->size += 1;
};

void pop(ArrayList* simpleArray, int index){
    checkAndQuench(simpleArray);
    for (int i = index; i < simpleArray->size - 1; i++){
        simpleArray->array[i] == simpleArray->array[i+1];
    }
    simpleArray->size -= 1;
};

void insert(ArrayList* simpleArray, int index, int value){
    if (index >= simpleArray->size){
        printf("Index does not exist\n");
        exit(1);
    }
    checkAndDoubleSize(simpleArray);
    int dummyValue = simpleArray->array[index];
    for (int i = index; i < simpleArray->size - 1; i++){
        simpleArray->array[i] = value;
        value = dummyValue;
        dummyValue = simpleArray->array[i+1];
    }
    simpleArray->array[simpleArray->size - 1] = dummyValue;
    simpleArray->size += 1;
};

ArrayList slice(ArrayList* simpleArray, int from, int to, bool inplace){
    if (to <= from){
        printf("from index must be greater than to index\n");
        exit(1);
    }
    if (inplace){
        ArrayList slicedArray;
        slicedArray.size = to - from;
        slicedArray.capacity = (int)(2*to-from);
        slicedArray.array = (int*)&(simpleArray->array[from]);
        return slicedArray;
    } else {
        ArrayList slicedArray;
        slicedArray.size = to - from;
        slicedArray.capacity = (int)(2*to-from);
        slicedArray.array = (int*)calloc(slicedArray.capacity, sizeof(int));
        int increment = 0;
        for (int i = from; i < to; i++){
            slicedArray.array[increment] = simpleArray->array[i];
            increment += 1;
        }
        return slicedArray;
    }
}

ArrayList initArrayList(){
    ArrayList array = {0};
    return array;
};

int main(){
    ArrayList simpleArray = initArrayList();
    for (int i = 0; i < 40; i++){
        push(&simpleArray, i);
        printf("capacity : %d, size : %d, value: %d\n", simpleArray.capacity, simpleArray.size, simpleArray.array[i]);
    }
    free(simpleArray.array);
    return 0;
}
