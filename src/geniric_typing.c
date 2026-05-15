
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "../include/generic_typing.h"

typedef struct Value {
    void *data;
    Type type;
    size_t size;
    // int owns_data;
} Value;


/* definitions */
Value *create_data(const void *data, Type type, size_t size){
    Value *value = malloc(sizeof(*value));

    if (!value)
        return NULL;

    value->data = malloc(size);

    if (!value->data) {
        free(value);
        return NULL;
    }

    memcpy(value->data, data, size);

    value->size = size;
    value->type = type;

    return value;
}


int _free_data(Value *value){
    if (!value)
        return 1;

    free(value->data);
    value->data = NULL;

    return 0;
}


int destroy_data(Value **value){
    if (!value || !(*value))
        return 1;

    _free_data(*value);

    free(*value);
    *value = NULL;

    return 0;
}


void print_data(const Value *value){
    if (!value || !(value->data)) 
        return;
    
    switch ((int)value->type) {
        case BOOL:
            if (*(int *)value->data == 0)
                printf("FALSE");
            else 
                printf("TRUE");
            break;
        case CHAR:
            printf("%c", *(char *)value->data);
            break;
        case INT:
            printf("%d", *(int *)value->data);
            break;
        case FLOAT:
            printf("%f", *(float *)value->data);
            break;
        case DOUBLE:
            printf("%lf", *(double *)value->data);
            break;
        default:
            fprintf(stderr, "Inconnu Type of data !");
    }
}


void print_data_string(const char *beggin_prompt, Value *value, const char *end_prompt){
    printf("%s", beggin_prompt); 
    print_data(value);
    printf("%s", end_prompt); 
}


int set_data(Value **dst, void *data, Type type, size_t size){
    if (!data || (!dst && !(*dst)))
        return 1;
    // free_data(*dst);
    // memcpy((*dst)->data, data, size);
    // (*dst)->size = size;
    // (*dst)->type = type;
    destroy_data(dst);
    *dst = create_data(data, type, size);

    return 0;
}
