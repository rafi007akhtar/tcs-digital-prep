/** Modified fibonacci problem of CodeVita 2018
 * Input n and k
 * Input first k fibonacci terms
 * nth Fibonacci term = (product of previous k fibonacci terms nth time) MOD 10^9+7
 * Output nth fibonacci number
 * 1 <= n <= 10^6
 * 1 <= k <= 10
 * This solution takes O(n*k) time and O(n) space
 */


#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	int i;
	for (i = 0; i < t; i++)
	{
		long long int n, k;
		scanf("%lld %lld", &n, &k);
		
		int j;
		long long int inp[n];
		for (j = 0; j < k; j++)
		{
			scanf("%lld", &inp[j]);
			// printf("%lld", inp[j]);
		}

		int pos = 0;
		long long int mul = 1;
		int knew = k;
		for (j = 1; j < n-knew+1; j++)
		{
			int y;
			for (y = pos; y < k; y++)
			{
				mul = mul * inp[y];
				if (mul >= MOD)
					mul %= MOD;
			}
			inp[k] = mul;
			// printf("Next value: %lld\n", mul);
			mul = 1;
			k++;
			pos++;
		}
		printf("%lld\n", inp[n-1]);
	}

	return 0;
}
