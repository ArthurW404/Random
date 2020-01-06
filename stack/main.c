#include <stdio.h>

#include "stack.h"

int main (void) {
    Stack stack = create_stack();
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    while (stack_card(stack) != 0) {
        printf("Cardinality = %d\n", stack_card(stack));
        printf("%d\n", pop(stack));
    }
    printf("Cardinality = %d\n", stack_card(stack));
    printf("%d\n", pop(stack));
    delete_stack(stack);
    return 0;
}