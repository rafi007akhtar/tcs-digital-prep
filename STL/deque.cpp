/** Play with deque -- a container that can add / remove values from both ends */

#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	// Declare a deque, add 3 elements to its front, and 2 on its back
	deque <int> dq;
	dq.push_back(3); // DQ = [3]
	dq.push_back(12); // DQ = [3, 12]
	dq.push_back(-7); // DQ = [3, 12, -7]
	dq.push_front(1); // DQ = [1, 3, 12, -7]
	dq.push_front(2); // DQ = [2, 1, 3, 12, -7]


	// Print all the elements of dq
	cout << "Elements of deque:" << endl;
	for (int i = 0; i < dq.size(); i++)
		cout  << dq[i] << " ";
	cout << endl;

	// Delete a value from front and a value from back, and print the new deque
	dq.pop_back(); // -7 gets removed ==> DQ = [2, 1, 3, 12]
	dq.pop_front(); // 2 gets removed ==> DQ = [1, 3, 12]
	cout << "\nNew deque after popping:" << endl;
	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;

	return 0;
}

