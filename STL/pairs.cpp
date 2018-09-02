/** Using pairs in STL, perform operations on complex numbers */

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    // Input a complex number and add (2 + 3i) to it
    pair <int, int> c1;
    cout << "Enter real and imaginary parts of your complex number: ";
    cin >> c1.first; // real
    cin >> c1.second; // imaginary

    pair <int, int> c2 (2, 3); // represents 2 + 3i

    pair <int, int> sum; 
    sum = make_pair(c1.first + c2.first, c1.second + c2.second);
    cout << "Sum = " << sum.first << " + " << sum.second << "i" << endl;

    // Check if this complex number is greater than 5 + 5i
    if (sum > pair<int, int> (5,5)) // other operators: >=, <, <=, ==, !
        cout << "Number greater than 5 + 5i" << endl;
    else cout << "Number not greater than 5 + 5i" << endl;

    // Swap pair (x, 1) with pair (y, -1)
    pair <char, int> x = make_pair ('x', 1);
    pair <char, int> y = make_pair ('y', -1);

    cout << "Before swap: \n (" << x.first << ", " << x.second << ") \t (" << y.first << ", " << y.second << ")";

    swap(x, y);
    cout << "\nAfter swap: \n (" << x.first << ", " << x.second << ") \t (" << y.first << ", " << y.second << ")";

    return 0;
}