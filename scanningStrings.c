#include <stdio.h>

int main (void) {
    char cinp;
    cinp = getchar();
    putchar(cinp);

    printf("\n");

    char sinp[100];
    fgets(sinp, 100, stdin);
    fputs(sinp, stdout);
    return 0;
}