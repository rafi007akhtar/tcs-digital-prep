/** Find the nth Catalan number.
 * A Catalan number satifies the following two properties:
 * C(0) = C(1) = 1; C(n) = sum(C(i).C(n-i-1)), from i = 0 to n-1
 */

#include <bits/stdc++.h>
using namespace std;


unsigned long int catalan(int n)
{
	if (n <= 1) return 1;
	
	unsigned long int cat = 0;
	for (int i = 0; i < n; i++)
		cat += catalan(i) * catalan(n-i-1);
	return cat;
}

unsigned long int catalan_dp(int n)
{
	int cat[n];
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

	// int cat[n];
	// cat[0] = 1;
	
	cout << "Catalan number " << n << " = " << catalan_dp(n) << endl;

	return 0;
}