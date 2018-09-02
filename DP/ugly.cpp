/** An ugly number is the one divisible by 2, 3, or 5. Find the nth ugly number */

#include <bits/stdc++.h>

using namespace std;

int n;

bool comp (int a, int b)
{
    return a < b;
}

int main(int argc, char *argv[])
{
    cout << "Enter n: ";
    int n; 
    cin >> n;

    int ugly[n+1];
    ugly[0] = 1; // 1 is the first ugly number by convention

    int i2, i3, i5;
    i2 = i3 = i5 = 0; // indices pointing to the current ugly number

    int next2 = ugly[i2] * 2;
    int next3 = ugly[i3] * 3;
    int next5 = ugly[i5] * 5;

    // Fill all ugly numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        int nextUgly = min({next2, next3, next5}, comp);
        ugly[i] = nextUgly;

        if (nextUgly == next2)
        {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (nextUgly == next3)
        {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (nextUgly == next5)
        {
            i5++;
            next5 = ugly[i5] * 2;
        }
    }

    cout << "Ugly number " << n << " = " << ugly[n] << endl;

    return 0;
}