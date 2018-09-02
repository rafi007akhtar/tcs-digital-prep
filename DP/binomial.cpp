/** Fint the binomial coefficient C(n, k), where:
  * C(n, k) = n!/(k! * (n-k)!)
  Note:    C(n, k) = C(n-1, k-1) + C(n-1, k)
*/

#include <bits/stdc++.h>
using namespace std;

long int C[100][100];

long int getC(int n, int k)
{
	// base cases
	if (n == 0 && k == 0) return 0;
	if (n < k) return 0;
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;

	// already solved
	if (C[n][k] != -1)
		return C[n][k];
	
	return C[n][k] = getC(n-1, k-1) + getC(n-1, k);
}

int main(int argc, char *argv[])
{
	int n, k;
	cout << "Enter n and k: ";
	cin >> n >> k;

	memset(C, -1, sizeof C);
	for (int i = 1; i <= n; i++)
	{
		C[i][0] = 1; // C(n,0) = 1
		C[i][1] = i; // C(n, 1) = 1
		C[i][i] = 1;
	}
	C[0][0] = 0;

	cout << "C(" << n << ", " << k << ") = " << getC(n, k) << endl;
	

	return 0;
}
