/** Compute Fibonacci numbers in two ways -- top-down and bottom up.
 * Take inputs from command-line arguments
*/

#include <stdio.h>
#include <stdlib.h>

int cache[100];

int fib_tab(int n)
{
    // returns nth fibonacci numbers using tabulation
    // assumes cache[0] = cache[1] = 1
    int i;
    for (i = 2; i <= n; i++)
        cache[i] = cache[i-1] + cache[i-2];
    return cache[n];
}

int fib_mem(int n)
{
    // returns nth fibonacci numbers using tabulation
    // assumes cache[0] = cache[1] = 1
    if (n <= 1)
        cache[n] = 1;
    else cache[n] = fib_mem(n-1) + fib_mem(n-2);
    return cache[n];
}

int main(int argn, char *argv[])
{
    int n;
    if (argn < 2)
    {
        printf("Error: Too few arguments (expected input number through command-line)\n");
        exit(0);
    }
    n = atoi(argv[1]);

    cache[0] = cache[1] = 1; // initial conditions
    printf("fib(%d) = %d using tabulation\n", n, fib_tab(n)); // bottom-up

    cache[0] = cache[1] = 1; // initial conditions
    printf("fib(%d) = %d using memoization\n", n, fib_mem(n)); // top-down

    int a = 10, x = 20;
    a = a++ + 10;
    x = x++ + ++a;
    printf("%d %d\n", a,x);
    
    return 0;
}
