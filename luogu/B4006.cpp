#include <cstdio>
#include <algorithm>
using namespace std;
int a[10001], n, k, ans;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j >= 1; j--)
        {
            if (a[i] - a[j] <= k)
            {
                sum += a[j];
            }
        }
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}