#include <cstdio>
int cnt[10];
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        for (int tmp = i; tmp; tmp /= 10)
        {
            cnt[tmp % 10]++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", cnt[i]);
    }
}