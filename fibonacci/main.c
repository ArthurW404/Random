// prints fibonacci numbers  
#include <stdio.h>

unsigned long print_fib (unsigned long num1, unsigned long num2);

int main (void) {
    print_fib(1,1);
    return 0;
}

unsigned long print_fib (unsigned long num1, unsigned long  num2) {
    printf("%lu\n", num2);
    if (num1 > 10000000000000000000) {
        printf("end\n");
        return 0;
    }
    return print_fib(num1 + num2, num1);
}