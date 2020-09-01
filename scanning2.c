#include <stdio.h>

int main (void) {
    int exit_condition = 1;
    while (exit_condition == 1) {
        int input1;
        int i = 0;
        printf("Enter Instructions: ");
        exit_condition = scanf("%d", &input1);
        while (i < input1) {
            int input2;
            scanf("%d", &input2);
            // do something with the number, probs add into array or something
            i++;
        }
    }
    return 0;
}   