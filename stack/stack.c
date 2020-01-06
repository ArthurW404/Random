#include <stdio.h>
#include <stdlib.h>

struct ll {
    // actual information from each stack node
    int data;
    struct ll *next;
};
typedef struct ll *Frame;

struct stack {
    int size;
    Frame head;
};
typedef struct stack *Stack;


Stack create_stack (void) {
    Stack new = malloc(sizeof(Stack));
    new->size = 0;
    new->head = NULL;
    return new;
}

void push (Stack stack, int input) {
    // add to top of the stack
    Frame new = malloc(sizeof(Frame));
    new->data = input;
    stack->size++;
    if (stack->head == NULL) {
        stack->head = new;
        return;
    }
    Frame curr = stack->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }   
    curr->next = new;

}

int pop (Stack stack) {
    // returns data of the top of the stack
    if (stack == NULL || stack->head == NULL) {
        printf("The stack is empty\n");
        exit(1);
    }
    stack->size--;
    Frame curr = stack->head;
    Frame prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    int to_return = curr->data;
    if (prev == NULL) {
        stack->head = NULL;
    } else {
        prev->next = NULL;
    }
    free(curr);
    return to_return;
}

int stack_card (Stack stack) {
    return stack->size;
}

void delete_stack (Stack stack) {
    Frame curr = stack->head;
    Frame prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(stack);
}

