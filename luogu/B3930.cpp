#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
inline int min(int a, int b = 32)
{
    return (a < b) ? a : b;
}
long long a[1000006], maxn = -1e9 - 7;
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(1 + a, a + n + 1,cmp);
    n = min(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long long temp = a[i] & a[j];
            if (i != j && temp > maxn)
            {
                maxn = temp;
            }
        }
    }
    printf("%lld", maxn);
}