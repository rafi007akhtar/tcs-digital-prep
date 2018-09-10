#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n & 1) // returns true if odd
        printf("Odd number\n");
    else
        printf("Even number\n");
    
    return 0;
}
