/**
 *Very gimped loading animation on command line 
 */
#include <stdio.h>
#include <unistd.h>

#define ANSI_COLOR_RED "\x1b[31m"

#define ANSI_COLOR_GREEN "\x1b[32m"

#define ANSI_COLOR_YELLOW "\x1b[33m"

#define ANSI_COLOR_BLUE "\x1b[34m"

#define ANSI_COLOR_MAGENTA "\x1b[35m"

#define ANSI_COLOR_CYAN "\x1b[36m"

#define ANSI_COLOR_RESET "\x1b[0m"

int main (void) {
    int i = 0;
    printf("[         ]"ANSI_COLOR_CYAN);
    while (i < 10) {
        printf("\b");
        fflush(stdout);
        i++;
    }
    i = 0;
    while (i < 3) {
        printf("--"">");
        fflush(stdout);

        sleep(1);
        i++;
    }
    i = 0;
    printf("\r");
    printf(ANSI_COLOR_GREEN"Success         \n");
   
    fflush(stdout);
    return 0;
}