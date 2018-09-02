/** Given 3 numbers {1, 3, 5}, we need to tell the total number of ways we can form a number 'N' using the sum of the given three numbers. */

/** EXAMPLES
    Total number of ways to form 6 is: 8
    1+1+1+1+1+1
    1+1+1+3
    1+1+3+1
    1+3+1+1
    3+1+1+1
    3+3
    1+5
    5+1
*/

#include <stdio.h>
#include <stdlib.h>

int cache[100];

int solve(int n)
{
    // base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;

    // if already calculated, return the value
    if (cache[n] != 0) return cache[n];

    return cache[n] = solve(n-1) + solve(n-3) + solve(n-5);
}

int main(int argc, char *argv[])
{
    int n;
    if (argc < 2)
    {
        printf("Error: Expected input number through command-line\n");
        exit(0);
    }
    n = atoi(argv[1]);

    int ways = solve(n);
    printf("Number of ways to form %d using 1, 3, 5 = %d\n", n, ways);

    return 0;
}
