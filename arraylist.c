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
    
    for(int n=l->size-1;n>=i;n--){  
       l->data[n+1]=l->data[n];     
    }
    l->size++;
    l->data[i]=data;
}

void* pop(ArrayList * l, int i){
    if(i>=l->size)return NULL;
    if (i < l->size *-1)return NULL;
    int n=i;
    if(i<0)n+=l->size;
    for(;n<l->size;n++){  
       l->data[n]=l->data[n+1];     
    }
    l->size--;
    return l->data[i];
}

void* get(ArrayList * l, int i){
    if(i>=l->size)return NULL;
    if (i < l->size *-1)return NULL;
    if(i<0)return l->data[l->size+i];
    return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    free(l);
    l=createList();
}
