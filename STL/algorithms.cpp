/** Simple program that uses STL functions to sort a user-given array, and perform binary search on it. */

#include <iostream>
#include <algorithm> // TODO: fill this comment w/ different algos this contains

using namespace std;

void printArray(int arr[], int size)
{
    // int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int arr[10];
    
    cout << "Enter 10 elements:\n";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    
    // SORTING
    sort(arr, arr+10);
    cout << "The sorted array is: \n";
    printArray(arr, 10);

    // SEARCHING
    int key;
    cout << "Enter the key to search in this array: ";
    cin >> key;
    if (binary_search(arr, arr+10, key))
        cout << "Element present" << endl;
    else cout << "Element not present";

    return 0;
}