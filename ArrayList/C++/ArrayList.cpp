#include<stdlib.h>
#include<stdbool.h>

template <typedef T, int initSize>
class ArrayList
{
    private:
        int size;
        int capacity;
        T* array;
    
        void checkAndDoubleSize(){
            if (this->size == this->capacity){
                int* newArr;
                if (this->capacity == 0 ){
                    // newArr = new T[initSize]();  
                    newArr = T[initSize];  
                    this->capacity = 1;
                } else {
                    // newArr = new T[2*(this->capacity)]();
                    newArr = T[2*(this->capacity)];
                    this->capacity *= 2;
                }
                    
                for (int i = 0; i < this->size; i++){
                    newArr[i] = this->array[i];
                }
                delete this->array;
                this->array = newArr;
            }
        }    

        void checkAndQuench(){
            if (this->size < this->capacity/4-4){
                this->capacity = this->capacity/4;
                int* newArray;
                // newArray = new T[this->capacity]();
                newArray = T[this->capacity];
                for (int i = 0; i < this->size; i++){
                    newArray[i] = this->array[i];
                }
                delete this->array;
                this->array = newArray;
            }
        }

    public:
        ArrayList(){
            this->size = initSize;
            this->capacity = initSize + 1;
            // this->array = new T[this->capacity]();
            this->array = T[this->capacity];
        }
        
        ~ArrayList(){
            delete this->array;
        }

        void push(int newVal){
            if(this->size == 0){
                this->capacity = 0;
            }
            this->checkAndDoubleSize();
            this->array[this->size] = newVal;
            this->size += 1;
        }

        void pop(int index){
            this->checkAndQuench();
            for (int i = index; i < this->size; i++){
                this->array[i] = this->array[i + 1]; 
            }
            this->size -= 1;
        }

        void insert(int index, int value){
            if (index >= this->size){
                printf("Index does not exist\n");
                exit(1);
            }
            checkAndDoubleSize();
            int dummyValue = this->array[index];
            for (int i = index; i < this->size - 1; i++){
                this->array[i] = value;
                value = dummyValue;
                dummyValue = this->array[i+1];
            }
            this->array[this->size - 1] = dummyValue;
            this->size += 1;
        }

        ArrayList slice(int form , int to, bool inplace){
            if (to <= from){
                printf("from index must be greater than to index\n");
                exit(1);
            }
            if (inplace){
                ArrayList slicedArray;
                slicedArray.size = to - from;
                slicedArray.capacity = slicedArray.size;
                slicedArray.array = (int*)&(this->array[from]);
                return slicedArray;
            } else {
                ArrayList slicedArray;
                slicedArray.size = to - from;
                slicedArray.capacity = slicedArray.size;
                slicedArray.array = (T*)&T[slicedArray.capacity];
                int increment = 0;
                for (int i = from; i < to; i++){
                    slicedArray.array[increment] = this->array[i];
                    increment += 1;
                }
                return slicedArray;
            }

        }

        T getValue(int index){
            if (index < this->size){
                return this->array[index]
            }
            printf("This is out of index");
            exit(1);
        }
};