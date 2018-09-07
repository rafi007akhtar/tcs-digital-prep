/** MERGE SORT
 * Input: an unsorted vector of ints
 * Output: the same vector sorted through merge sort
 * Time: O(n lg n)
 * NOTE: The program doesn't work yet. 
 * TODO: Make the program work.
 */

#include "utilities.hpp"
#include <climits>

vector <int> merge(vector <int>, int, int, int);
vector <int> mergeSort(vector <int>, int begin, int end);

int main(void)
{
	// TEST for MERGE function
	// vector <int> v1 = {1,3,5,-1,2,4,6};
	// vector <int> v2 = {1,3,4,5,8};
	// vector <int> merged = merge(v1,0,2,6);
	// printV(merged);

	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	vector <int> v(n);

	cout << "Enter " << n << " elements:\n";
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	int begin, end;
	begin = 0;
	end = n-1;
	v = mergeSort(v, begin, end);

	cout << "Sorted elements:\n";
	printV(v);

	return 0;
}

vector <int> merge(vector <int> v, int begin, int mid, int end)
{
	/** v is a vector such that the subvectors v[begin:mid] and v[mid+1:end] are sorted
	 * combine these subvectors to result a sorted vector
	 */

	vector <int> left, right;

	// fill in data into left subvector
	for (int i = begin; i <= mid; i++)
		left.push_back(v[i]);
	
	for (int i = mid+1; i <= end; i++)
		right.push_back(v[i]);

	// cout << "Left sub: ";
	// printV(left);
	// cout << "Right sub: ";
	// printV(right);
	
	// Append sentinels to each of the vectors
	left.push_back(INT_MAX);
	right.push_back(INT_MAX);

	// Track positions of v1 and v2
	int pos1, pos2;
	pos1 = pos2 = 0;

	// Merging happens here
	for (int i = 0; i < v.size(); i++)
	{
		if (left[pos1] < right[pos2])
			v[i] = left[pos1++];
		else
			v[i] = right[pos2++];
	}

	return v;
}

vector <int> mergeSort(vector <int> v, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		vector <int> firstHalf = mergeSort(v, begin, mid);
		vector <int> secondHalf = mergeSort(v, mid+1, end);
		v = merge(v, begin, mid, end);
	}
	
	return v;	
}

