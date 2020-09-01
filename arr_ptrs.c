#include <stdio.h>
#include <stdlib.h>
void print_argv (int size, char *arr[]);


int main (int argc, char *argv[]) {
    printf("%s\n", getenv("PATH"));
    print_argv(argc - 1, &argv[1]);
    return 0;
}

void print_argv (int size, char *argv[]){
    for (int i = 0; i < size; i++) {
        printf("%s ",argv[i]);
    }
}