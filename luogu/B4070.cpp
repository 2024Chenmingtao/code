#include <iostream>
#include <cmath>

using namespace std;


int calculateTerms(int exponent)
{
    return (sqrt(1 + 8LL * exponent) - 1) / 2;
}

int main()
{
    long long x;
    cin >> x;
    long long result = 0;

    for (long long factor = 2; factor <= x / factor; ++factor)
    {
        if (x % factor == 0)
        {
            int cnt = 0;
            while (x % factor == 0)
            {
                x /= factor;
                ++cnt;
            }
            result += calculateTerms(cnt);
        }
    }

    if (x > 1)
    {
        result += 1;
    }

    cout << result << endl;
    return 0;
}