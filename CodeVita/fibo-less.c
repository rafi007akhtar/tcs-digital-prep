/** This is a memory-optimized solution of Modified Fibonacci problem
 * This solution takes O(n*k) time but O(k) space
 * Recall 1 <= n <= 10^6 but 1 <= k <= 10
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
		long long int inp[k];
		for (j = 0; j < k; j++)
		{
			scanf("%lld", &inp[j]);
			// printf("%lld", inp[j]);
		}

		int prevPos, pos = 0, y;
		long long int mul = 1;

        for (j = 1; j < n-k+1; j++)
        {
            for (y = 0; y < k; y++)
            {
                mul *= inp[y];
                if (mul >= MOD) mul %= MOD;
            }
            
            inp[pos] = mul;
            mul = 1;
            // printf("inp[%d]: %lld\n", pos, inp[pos]);
            prevPos = pos;
            pos = (pos+1) % k;
        }
        

		printf("%lld\n", inp[prevPos]);
	}

	return 0;
}
