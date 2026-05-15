
#ifndef DATA
#define DATA

#include <stddef.h>

/* Type tagging */
typedef enum {
    BOOL   = 1,
    CHAR   = 2,
    INT    = 3,
    FLOAT  = 4,
    DOUBLE = 5
} Type;

typedef struct Value Value;

/* lyfecycle */
Value *create_data(const void *data, Type type, size_t size);
int destroy_data(Value **value);

/* Acceding */
void print_data(const Value *value);
void print_data_string(const char *beggin_prompt, Value *value, const char *end_prompt);

/* usefull */
int set_data(Value **dst, void *data, Type type, size_t size);

#endif /* DATA */
