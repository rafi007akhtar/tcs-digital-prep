/** Coin-change problem, with a different (and much simpler!) approach
 * Logic used:
	for all coins:
		if i > coin:
			change[i] += change[n-i]
	
 * I got the above logic and its tutorail here: https://youtu.be/jaNZ83Q3QGc
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int t; // number of test cases
	cout << "Enter number of test cases: ";
	cin >> t;

	while (t-- > 0)
	{
		// input N and S
		int n; 
		cout << "Enter n: ";
		cin >> n;

		vector <int> v;
		cout << "Enter value of coins, or -1 to stop:\n";
		while(1)
		{
			int temp;
			cin >> temp;
			if (temp == -1) break;
			v.push_back(temp);
		}
		// now we have N and S

		int change[n+1];
		memset(change, 0, sizeof change);
		change[0] = 1;
		for (int i: v)
		{
			for (int j = 0; j <= n; j++)
			{
				if (j >= i)
					change[j] += change[j-i]; // this is where the logic applies
			}
		}

		cout << "Ways: " << change[n] << endl;
	}

	return 0;
}
