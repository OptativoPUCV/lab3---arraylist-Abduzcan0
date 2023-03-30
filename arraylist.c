#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *list = NULL;
    list = (ArrayList*) malloc(sizeof(ArrayList));
    if (list == NULL) exit(EXIT_FAILURE);
    list->data = (void **) calloc(2, sizeof(void*));
    list->capacity = 2;
    list->size = 0;

    return list;
}

void append(ArrayList * l, void * data){
    
    if(l->size==l->capacity){
        l->capacity*=2;
        l->data =(void**) realloc(l->data,l->capacity*sizeof(void*));
        if (l == NULL) exit(EXIT_FAILURE);  
    }
    l->data[l->size]=data;
    l->size++;
}

void push(ArrayList * l, void * data, int i){

    if(i>l->size)return;
    if(l->size==l->capacity){
        l->capacity*=2;
        l->data =(void**) realloc(l->data,l->capacity*sizeof(void*));
        if (l == NULL) exit(EXIT_FAILURE);  
    }
    for(int u=l->size-1;u>=0;u--){
        if(i==u){
            for(;u<l->size;u++){
                l->data[u]=l->data[u+1];
            }
            break;
        }
        
    }
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
