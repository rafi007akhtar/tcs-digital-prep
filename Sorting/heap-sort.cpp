/** HEAP SORT
 * Input: a vector of unsorted elements of size n
 * Output: the same vector sorted
 * Time: O(n lg n)
 
 PS. This program is only concerned with applying heapsort on a vector. It does not cover heap functions other than necessary. 
 Heaps in details are covered in another of my repositories, that can be found at:
 https://github.com/rafi007akhtar/c-algorithms/blob/master/heap-algos.c
 */

#include "utilities.hpp"

vector <int> heap; // the heap array

void maxHeapify(int i, int size)
{
	/** Max heapify elements below heap[i]. Assumptions:
	 * Elements above heap[i] are max-heapified
	 * heap[i] is smaller than its children
	 */

	int largest, left, right;
	left = i*2 + 1; // index of left child of heap[i]
	right = i*2 + 2; // index of right child of heap[i]
	
	// Pick the largest b/w heap[right], heap[left], heap[i]
	if (left < size && heap[left] > heap[i])
		largest = left;
	else largest = i;
	if (right < size && heap[right] > heap[largest])
		largest = right;

	if (largest != i)
	{
		// Replace heap[i] with heap[largest]
		int temp = heap[largest];
		heap[largest] = heap[i];
		heap[i] = temp;

		// Recurse on A[largest]
		maxHeapify(largest, size);
	}
}

void buildMaxHeap(int n)
{
	/** Build a max-heap from the input vector of size n */
	int nonLeafLast = (n-1)/2;
	for (int i = nonLeafLast; i >= 0; i--)
		maxHeapify(i, n);
}

void heapSort(int n)
{
	/** Apply heapsort on the array */

	buildMaxHeap(n);
	int end = n-1;
	for (int i = end; i > 0; i--)
	{
		// Swap heap[0] with heap[n], and cut if off
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		// Max-Heapify from the top to place max(heap) at the top
		maxHeapify(0, --n);
	}
}

int main()
{
	int n;
	cout << "Enter the number of elements in the list: ";
	cin >> n;

	cout << "Enter " << n << " elements:\n";
	int temp;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		heap.push_back(temp);
	}

	heapSort(n);

	cout << "The sorted elements are: ";
	printV(heap);

	return 0;
}
