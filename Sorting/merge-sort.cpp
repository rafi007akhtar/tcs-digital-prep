/** MERGE SORT
 * Input: an unsorted array of ints
 * Output: the same array sorted through merge sort
 * Time: O(n lg n)
 */

#include "utilities.hpp"

void mergeSort(int arr[], int begin, int end);
void merge(int arr[], int begin, int mid, int end);

int main()
{
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];

	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	mergeSort(arr, 0, n-1);
	cout << "Sorted array: ";
	printA(arr, n);

	return 0;
}

void mergeSort(int arr[], int begin, int end)
{
	/** Apply the merge sort algorithm to the array arr */

	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergeSort(arr, begin, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, begin, mid, end);
	}
}

void merge(int arr[], int begin, int mid, int end)
{
	/** arr is an array such that subarray arr[0:mid] and arr[mid+1:end] are sorted
	 * Merge them in a way that arr becomes sorted
	 */

	// create left and right subarrays
	int sizeL = mid-begin+1;
	int sizeR = end-mid;
	int left[sizeL];
	int right[sizeR];

	// add elements to left and right
	for (int i = 0; i < sizeL; i++)
		left[i] = arr[begin + i];
	for (int i = 0; i < sizeR; i++)
		right[i] = arr[mid+i+1];

	int l = 0; // base index of left subarray
	int r = 0; // base index of right subarray
	int k = begin; // base index of merged array

	// the merge process
	while (l < sizeL && r < sizeR)
	{
		if (left[l] < right[r])
			arr[k++] = left[l++];
		else
			arr[k++] = right[r++];
	}

	// append remaining elements
	while (l < sizeL)	arr[k++] = left[l++];
	while (r < sizeR)	arr[k++] = right[r++];

}
