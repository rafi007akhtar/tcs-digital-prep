/** Play with lists, that are doubly-linked lists where you can add / remove elements in constant time, but there's no random access -- that's why the foreach loop.
 * NOTE: foreach loops work with other containers as well.
 */

#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	// Create a list and add 1,2,3,4,5 to it
	list <int> lst;
	for (int i = 1; i <= 5; i++)
		lst.push_back(i);

	// Print the values
	cout << "The values in the list are:" << endl;
	for (int i: lst)
		cout << i << " ";
	cout << endl;

	// Add an element to the beginning
	lst.push_front(10);
	cout << "\nElement prepended: " << *lst.begin() << endl;

	// Remove one element from front and back each, and reprint the list (current list: [10,1,2,3,4,5])
	lst.pop_back(); // [10,1,2,3,4]
	lst.pop_front(); // [1,2,3,4]
	cout << "\nList after popping: " << endl;
	for (int i: lst) 
		cout << i << " ";
	cout << endl;

	return 0;
}