#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    (n & 1) ? printf("Odd number\n") : printf("Even number\n");
    
    return 0;
}
