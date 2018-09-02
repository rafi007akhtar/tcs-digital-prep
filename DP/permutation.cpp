/** Fint the permutation coefficient P(n, k), where:
  * P(n, k) = n!/((n-k)!)
  Note:   P(n, k) = P(n-1, k) + k* P(n-1, k-1)   

*/

#include <bits/stdc++.h>
using namespace std;

long int P[100][100];

long int getP(int n, int k)
{
	// base cases
	if (n == 0 && k == 0) return 0;
	if (n < k) return 0;
	if (k == 0) return 1;
	if (k == 1) return n;

	// already solved
	if (P[n][k] != -1)
		return P[n][k];
	
	return P[n][k] = getP(n-1, k) + k*getP(n-1, k-1);
}

int main(int argc, char *argv[])
{
	int n, k;
	cout << "Enter n and k: ";
	cin >> n >> k;

	memset(P, -1, sizeof P);
	for (int i = 1; i <= n; i++)
	{
		P[i][0] = 1; // C(n,0) = 1
		P[i][1] = i; // C(n, 1) = 1
	}
	P[0][0] = 0;

	cout << "P(" << n << ", " << k << ") = " << getP(n, k) << endl;
	

	return 0;
}
