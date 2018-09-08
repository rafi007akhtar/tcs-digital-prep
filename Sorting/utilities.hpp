/** Contains utility functions for sorting programs */

#include <bits/stdc++.h>
using namespace std;

void printV(vector <int> v)
{
	/** Print the elements of an int vector, separate them using spaces, and append a newline at the end of it */
	for (int i: v)
		cout << i << " ";
	cout << endl;
}

void printA(int arr[], int size)
{
	/** Print the elements of an int array[size], separate them using spaces, and append a newline at the end of it */
	// vector <int> v (begin(arr), end(arr));
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
