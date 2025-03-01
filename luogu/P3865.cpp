#include <cstdio>
#include <cmath>
#define MAXN 100009
#define LOGMAXN 100
int n, m;
int st[MAXN][LOGMAXN];
inline int max(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &st[i][0]);
    }
    for (int j = 1; j <= (int)log2(n); j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int s = (int)log2(r - l + 1);
        printf("%d\n", max(st[l][s], st[r - (1 << s) + 1][s]));
    }
}