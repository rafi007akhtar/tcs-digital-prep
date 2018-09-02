/** Playing with vectors */

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// Create a vector with containing 0, 10, 20, ..., 90
	vector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
		v1[i] = i*10;
	
	// Print the elements
	cout << "Elements of vector v1:" << endl;
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	// Add a new element at its end, and print it
	v1.push_back(55);
	cout << "New element added: " << v1[v1.size()-1] << endl;

	// Resize so v1 could contain 15 elements
	v1.resize(15);
	// Copy this resized vector into another vector v2
	vector <int> v2(v1);

	cout << "\nElements of new vector v2:" << endl;
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	return 0;
}
