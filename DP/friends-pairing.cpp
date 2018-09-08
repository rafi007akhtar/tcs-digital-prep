/** 
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Example :

Input  : n = 3
Output : 4

Explanation
{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

LOGIC:
	i) nth person remains single in 1 way; n-1 will pair up or be single in f(n-1) ways
		# of ways = 1*f(n-1) = f(n-1)
	ii) nth person pairs with one of the (n-1)th people remaining in n-1 ways; remaining n-2 people pair up or remain single in f(n-2)
		# of ways = (n-2)f(n-2)

	Therefore, total ways = f(n-1) + (n-1)f(n-2)
*/

#include <bits/stdc++.h>
using namespace std;

int getNumberOfPairs(int);
int ways[100];

int main(void)
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	// ways = new int[n+1];

	memset(ways, -1, sizeof ways);
	int pairings = getNumberOfPairs(n);
	cout << "Number of ways: " << ways[n] << endl;

	return 0;
}

int getNumberOfPairs(int n)
{
	// if no person is there, there is no way of pairing up or being single
	if (n <= 0) return 0;

	// if only one person is there, there is only one way where he/she has to remain single
	if (n == 1) return 1;

	if (n == 2) return 2; // either they pair up or each remain single

	if (ways[n] != -1) // already calculated, then simply return the result instead of recomputing
		return ways[n];
	
	// otherwise, follow the logic
	return ways[n] = getNumberOfPairs(n-1) + (n-1)*getNumberOfPairs(n-2);
}
