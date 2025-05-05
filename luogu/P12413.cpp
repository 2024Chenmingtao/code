#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
long long n, w, a[500005], ans = 0;
int main()
{
    scanf("%d%d", &n, &w);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; i++)
    {
        a[i] = max(a[i] - i + 1, (long long)(0));
    }
    sort(a + 1, a + n + 1, greater<long long>());
    ans = a[w];
    long long answer = 0;
    for (long long i = 1; i <= n; i++)
    {
        answer += max(a[i] - ans, (long long)0);
    }
    answer += ans * w;
    printf("%lld", answer);
}