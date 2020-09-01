/**
 * @author Arthur Wang 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct array {
    int *num_arr;
    int max_size;
    int curr_size;
};

typedef struct array *Array;

Array create_array();
void read_input(Array input_array);
void print_arr(int *inputs, int size);
void print_missing(int *inputs, int size);
int get_smallest_num(int *inputs, int size);
int get_largest_num(int *inputs, int size);
bool is_missing (int num, int *num_arr, int size);

int main (void) {
    Array input_array = create_array();
    read_input(input_array);
    print_missing(input_array->num_arr, input_array->curr_size);
    // print_arr(inputs, size);
    return 0;
}

Array create_array() {
    Array arr = malloc(sizeof(struct array));
    arr->curr_size = 0;
    arr->max_size = 100;
    arr->num_arr = malloc (arr->max_size * sizeof(int));
    return arr;
}

/**
 * Scans number inputs (program bugs out if they enter characters)
 */
void read_input(Array inputs) {
    int curr = 0;
    for (;scanf("%d", &inputs->num_arr[curr++]) != EOF;) {
        if (curr == inputs->max_size) {
            inputs->max_size = 2 * inputs->max_size;
            inputs->num_arr = realloc(inputs->num_arr, inputs->max_size * sizeof(int));
        }
    }
    inputs->curr_size = curr;
}


/**
 * Function checks whether num is in the array num_arr, print true if 
 * it isn't in the array
 */
bool is_missing (int num, int *num_arr, int size) {
    for (int i = 0; i < size; i++) {
        if (num == num_arr[i]) {
            return false;
        }
    }
    return true;
}

/**
 * Function which prints all the missing numbers between the inputs
 */
void print_missing(int *inputs, int size) {
    int smallest_num = get_smallest_num(inputs, size);
    int largest_num = get_largest_num(inputs, size);
    for (int i = smallest_num; i < largest_num; i++) {
        if (is_missing(i, inputs, size))
            printf("%d ", i);
    }
    printf("\n");
}

/**
 * Function returns the smallest number in an integer array
 */
int get_smallest_num(int *inputs, int size) {
    if (size == 0) {
        fprintf(stderr, "Warning: array is empty\n");
        exit(EXIT_FAILURE);
    }

    int smallest = inputs[0];
    for (int i = 1; i < size; i++) {
        if (inputs[i] < smallest) 
            smallest = inputs[i];
    }
    return smallest;
}

/**
 * Function returns the largest number in an integer array
 */
int get_largest_num(int *inputs, int size) {
    if (size == 0) {
        fprintf(stderr, "Warning: array is empty\n");
        exit(EXIT_FAILURE);
    }

    int largest = inputs[0];
    for (int i = 1; i < size; i++) {
        if (inputs[i] > largest) 
            largest = inputs[i];
    }
    return largest;
}

/**
 *  Used for debugging arrays 
 */
void print_arr(int *inputs, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", inputs[i]);
    }
    printf("\n");
}