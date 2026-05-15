
#include "../include/generic_typing.h"


/* Main */
int main(void){
    int data = 5;
    Value *x = create_data(&data, INT, sizeof(int));

    print_data_string("\nValue: ", x, "\n");

    data = 97;
    set_data(&x, &data, CHAR, sizeof(int));
    print_data_string("\nValue: ", x, "\n");

    print_data_string("\nValue: ", x, "\n");
    destroy_data(&x);
    return 0;
}
