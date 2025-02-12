#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6; // 预处理到1e6

int minPrime[MAX + 1];

void euler_sieve()
{
    for (int i = 2; i <= MAX; ++i)
    {
        if (minPrime[i] == 0)
        { // 如果i是质数
            minPrime[i] = i;
            for (int j = i * 2; j <= MAX; j += i)
            {
                if (minPrime[j] == 0)
                {
                    minPrime[j] = i;
                }
            }
        }
    }
}

int main()
{
    euler_sieve(); // 预处理最小质因数

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        if (minPrime[x] == x)
        { // x是质数
            cout << 0 << endl;
        }
        else
        {
            int cnt = 0;
            int prev = 0;
            int tmp = x;

            while (tmp > 1)
            {
                int p = minPrime[tmp];
                if (p != prev)
                {
                    cnt++;
                    prev = p;
                }
                while (tmp % p == 0)
                {
                    tmp /= p;
                }
            }

            if (cnt == 2)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}