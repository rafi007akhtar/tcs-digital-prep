#include "utilities.hpp"

void quickSort(int arr[], int begin, int end);
int partition(int arr[], int start, int end);

int main(void)
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    quickSort(arr, 0, n-1);
    cout << "Sorted array:\n";
    printA(arr, n);

    return 0;
}

void quickSort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        int ind = partition(arr, begin, end); // get the partition index
        quickSort(arr, begin, ind-1);
        quickSort(arr, ind+1, end);
    }
}

int partition(int arr[], int begin, int end)
{
    int pivot = arr[end]; // pivot
    int ind = begin; // partition index

    // partition process:
    for (int i = begin; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[ind];
            arr[ind++] = temp;
        }
    }
    // swap arr[end] with arr[ind]
    int temp = arr[end];
    arr[end] = arr[ind];
    arr[ind] = temp;

    return ind;
}
