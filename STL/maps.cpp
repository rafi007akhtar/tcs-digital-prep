/** Generate an ASCII table from A-Z using maps.
 * Maps is a container that stores pairs in it.
 */

#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map <int, char> ascii;
	for (int i = 65; i <= 90; i++)
	{
		pair <int, char> p;
		p.first = i;
		p.second = i; // equivalent char
		ascii.insert(p);
	}

	// Now print it
	cout << "ASCII table from A-Z \n--------------\n";
	for (pair <int, char> p : ascii)
		cout << p.first << ": " << p.second << "\t";
	cout << endl;

	cout << "\n(Test) \nAt 70: " << ascii[70] << endl;

	return 0;
}
