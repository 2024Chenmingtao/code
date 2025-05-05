#include <cstdio>
long long max(long long a, long long b)
{
    return a > b ? a : b;
}
int ans = 0, n, k, input;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &input);
        ans += k - input;
    }
    printf("%d", max(k - ans, 0));
    return 0;
}