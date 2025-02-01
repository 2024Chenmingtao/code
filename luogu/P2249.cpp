#include <cstdio>

int n, m;
int a[1000007];

int find(int l, int r, long long x)
{
    if (l == r)
    {
        if (a[l] == x)
        {
            return l;
        }
        return -1;
    }
    int mid = (l + r) / 2;
    if (a[mid] < x)
    {
        return find(mid + 1, r, x);
    }
    if (a[mid] >= x)
    {
        return find(l, mid, x);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        long long y;
        scanf("%lld", &y);
        printf("%d ", find(1, n, y));
    }
}