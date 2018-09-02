/** Print a sqaure matrix in spiral order.

Input:
[ 
  1, 2, 3,
  4, 5, 6,
  7, 8, 9
]

Output:
1, 2, 3, 6, 9, 8, 7, 4, 5
*/


#include <stdio.h>
#include <stdlib.h>

int n, i, j; // n x n is the order of the matrix
char dir; // direction to traverse (right (r), down (d), left (l), top (t))
int **arr;

void move(); // determines which direction to go next (r,d,l,t)

int main(void)
{
    int p, count, elem;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    arr = (int **)malloc(n*sizeof(int*));
    for (j = 0; j < n; j++)
        arr[j] = (int *)malloc(n*sizeof(int));

    printf("Enter elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    i = j = 0; // initally print arr[0][0]
    dir = 'r'; // initially move right
    count = 0;
    elem = n*n; // number of elements in the matrix

    printf("\nThe elements in spiral order are: \n");
    while (1)
    {
        if (count == elem) // if all elements are printed in spiral order, stop
            break;
        if (arr[i][j] != -1) // if present location doesn't contain a sentinel
        {
            printf("%d ", arr[i][j]);
            arr[i][j] = -1; // print and replace with sentinel
            count++;
        }
        move(); // compute where to go next
    }
    printf("\n");

    return 0;
}

void move()
{
    switch(dir)
    {
        case 'r': // if you're going right
            if (j == n-1) // if you have reached a boundary, change direction
                dir = 'd';
            else if (arr[i][j+1] == -1)  // OR, if the next element is a sentinel, change direction
                dir = 'd'; // right is followed by down
            else j++; // this is how we go right
            
            break;
        
        case 'd':
            if (i == n-1 || arr[i+1][j] == -1)
                dir = 'l';
            else i++; // this is how we move down
            break;
        
        case 'l':
            if (j-1 == -1 || arr[i][j-1] == -1)
                dir = 't';
            else j--; // this is how we move left
            break;

        case 't':
            if (arr[i-1][j] == -1)
                dir = 'r';
            else i--; // this is how we move up
            break;
    }
}
