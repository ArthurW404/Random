#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int i = 0;

int fib(int n);

int *dynamic_store = NULL;

main () {
   int n = 100000;
   dynamic_store = malloc (n * sizeof(int));
   for (int i = 0; i <= n; i++)
      dynamic_store[i] = 0;
   printf("%d\n", fib(n));
}

int fib(int n)
{
   assert(n > 0);
   i++;
   if (n == 1 || n == 2)
      return 1;
   else if (dynamic_store[n] != 0)
      return dynamic_store[n];
   else
      dynamic_store[n] = fib(n-1) + fib(n-2);
      return dynamic_store[n];
}
