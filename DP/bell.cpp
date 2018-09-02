/** 
	S(n, k) = k*S(n-1, k) + S(n-1, k-1)
	Bell(n) = sum(S(n,k)) from k = 1 to n
	First few Bell numbers are 1, 1, 2, 5, 15, 52, 203, ….
*/

#include <bits/stdc++.h>
using namespace std;

int S[100][100];

long int getS(int n, int k)
{
	// base cases
	if (k == 0 || n == 0 || k > n) return 0;
	if (k == n || k == 1) return 1;

	if (S[n][k] != -1) // already solved
		return S[n][k];

	return S[n][k] = k*getS(n-1, k) + getS(n-1, k-1);
}

long int bell(int n)
{
	long int sum = 0;
	for (int k = 1; k <= n; k++)
		sum += getS(n, k);
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	memset(S, -1, sizeof S);
	S[0][0] = 0;

	cout << "Bell(" << n << ") = " << bell(n) << endl;

	return 0;
}
