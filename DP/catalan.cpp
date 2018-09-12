/** Find the first n Catalan numbers.
 * A Catalan number satifies the following two properties:
 * C(0) = C(1) = 1; C(n) = sum(C(i).C(n-i-1)), from i = 0 to n-1
 */

#include <bits/stdc++.h>
using namespace std;

int *cat;

// DON'T CALL THIS FUNCTION
// It correctly computes Catalan numbers, but uses brute-force divide and conquer in doing so, and ends up taking a lot of time for larger numbers
unsigned long int catalan(int n)
{
	if (n <= 1) return 1;
	
	unsigned long int cat = 0;
	for (int i = 0; i < n; i++)
		cat += catalan(i) * catalan(n-i-1);
	return cat;
}

// CALL THIS FUNCTION
// It computes the first n Catalan numbers in shorter span of time using tabulation
unsigned long int catalan_dp(int n)
{
	// int cat[n];
	cat[0] = cat[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		cat[i] = 0;
		for (int j = 0; j < i; j++)
			cat[i] += cat[j] * cat[i-j-1];
	}

	return cat[n];
}

int main(int argc, char *argv[])
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	cat = new int[n+1];

	// int cat[n];
	// cat[0] = 1;
	
	cout << "Catalan numbers from 0 to " << n << " are:\n";
	for (int i = 0; i <= n; i++)
		cout << "catalan (" << i << ") = " << catalan_dp(i) << endl;

	return 0;
}