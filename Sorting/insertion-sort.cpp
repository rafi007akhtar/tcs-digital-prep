/** INSERTION SORT
 * Input: an unsorted vector
 * Output: the same vector sorted
 * Time: O(n^2) for worst case; O(n) for best case
 */

#include "utilities.hpp"

vector <int> insertionSort(vector <int>);

int main(void)
{
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	vector <int> v(n);

	cout << "Enter " << n << " elements:\n";
	int temp;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	v = insertionSort(v);

	cout << "Sorted elements: \n";
	printV(v);

	return 0;
}

vector <int> insertionSort (vector <int> v)
{
	/** Apply insertion sort on a vector and return the sorted vector */
	
	int l = v.size();
	for (int i = 1; i < l; i++)
	{
		int current = v[i];
		int j = i-1;
		while (current < v[j] && j >= 0)
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = current;
	}

	return v;
}
