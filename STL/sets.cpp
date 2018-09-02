/** Using sets to:
 * Remove duplicates from an array
 * Sorting an array
 */

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	// Create a set {1,2,3} and print it
	set <int> s1;
	s1.insert(1); // {1}
	s1.insert(1); // {1} as duplicates aren't allowed
	s1.insert(2); // {1,2}
	s1.insert(3); // {1,2,3}
	cout << "Elements of set: \n";
	for (int i: s1)
		cout << i << " ";
	cout << endl;

	// Remove duplicates from an array using sets
	int arr[] = {1,2,2,3,3,3,4,4,4,4};
	set <int> s2(begin(arr), end(arr));
	// Now print it
	cout << "Unique elements of array:\n";
	for (int i: s2)
		cout << i << " ";
	cout << endl;

	// Remove the element 2 from the set and print the new set
	s2.erase(2);
	cout << "\nNew set after removing 2:\n";
	for (int i: s2) cout << i << " ";
	cout << endl;

	// Sort an array in ascending order using sets
	int unsorted[] = {2,5,1,-3,0};
	set <int> sorted(begin(unsorted), end(unsorted));
	cout << "\nSorted array: \n";
	for (int i: sorted)
		cout << i << " ";
	cout << endl;

	return 0;
}
