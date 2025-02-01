#include <cstdio>
#include <algorithm>
int n, m, dp[30000], MIN = 1e9 + 7;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &dp[i]);
        dp[i] += dp[i - 1];
    }
    for (int i = m; i <= n; i++)
    {
        MIN = std::min(MIN, dp[i] - dp[i - m]);
    }
    printf("%d", MIN);
}