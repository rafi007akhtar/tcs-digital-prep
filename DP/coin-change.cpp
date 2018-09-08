/** Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

Examples: 
	* For N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
	* For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include <bits/stdc++.h>
using namespace std;

int count (vector <int>, int, int);
int change[100][100]; // assuming N and M can be as large as 100

int main(void)
{
	int t; // number of test cases
	cout << "Enter number of test-cases: ";
	cin >> t;

	while (t-- > 0)
	{
		// input the values N and S
		int n;
		cout << "Enter n: "; 
		cin >> n;

		cout << "Enter the values in the set, or -1 to exit:\n";
		vector <int> v;
		int temp;
		
		while(1)
		{
			cin >> temp;
			if (temp == -1) break;
			v.push_back(temp);
		}
		// now you have N and S

		int m = v.size();

		memset(change, -1, sizeof change);
		for (int i = 0; i < m; i++)
			change[0][i] = 1; // base case (only 1 solution for n=0)
		
		int changes = count(v, m, n);
		cout << "Ways = " << changes << endl;
	}

	return 0;
}

int count (vector <int> v, int m, int n)
{
	// if n < 0, then no solution exists
	if (n < 0) return 0;

	// if there are no cents, only one solution exists: choose no coin
	if (n == 0) return 1;

	// if there are cents (n) but no coins (m), then no solutions exists
	if (m <= 0 && n >= 1) return 0;

	// return change[n] if it already is computed
	if (change[n][m] != -1)
		return change[n][m];

	// finally, return the sum of two cases: without mth coin, and with atleast 1 mth coin
	return change[n][m] = count(v, m-1, n) + count(v, m, n-v[m-1]);

}
