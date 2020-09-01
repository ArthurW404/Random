#include <stdio.h>

int main (void) {
    char input;
    int condition = 0;
    while (condition != 1) {
        printf("Plz enter input:\n");
        input = getchar();
        if (input == 'q'){
            condition = 1;
        } else {
            printf("%c\n", input);
        }

    }
    return 0;

}
