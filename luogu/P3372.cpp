#include <cstdio>
long long tree[400010], a[100010], lazy[400010];
void down(int x, int l, int r)
{
    if (lazy[x] != 0)
    {
        int mid = (l + r) >> 1;
        int left_len = mid - l + 1;
        int right_len = r - mid;
        tree[x << 1] += lazy[x] * left_len;
        lazy[x << 1] += lazy[x];
        tree[(x << 1) + 1] += lazy[x] * right_len;
        lazy[(x << 1) + 1] += lazy[x];
        lazy[x] = 0;
    }
}
void build(int l, int r, int x)
{
    if (l == r)
    {
        tree[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;

    build(l, mid, (x << 1));

    build(mid + 1, r, (x << 1) + 1);

    tree[x] = tree[(x << 1)] + tree[(x << 1) + 1];
    return;
}
long long query(int L, int R, int l, int r, int x)
{
    if (L <= l && r <= R)
    {
        return tree[x];
    }
    if (lazy[x] != 0)
    {
        down(x, l, r);
    }

    int mid = (l + r) >> 1;
    long long ans = 0;
    if (L <= mid)
    {
        ans += query(L, R, l, mid, x << 1);
    }
    if (R > mid)
    {
        ans += query(L, R, mid + 1, r, (x << 1) + 1);
    }
    return ans;
}
void add_region_modify(int l, int r, int L, int R, int x, long long add_value)
{
    if (L <= l && r <= R)
    {
        tree[x] += add_value * (r - l + 1);
        lazy[x] += add_value;
        return;
    }
    int mid = (l + r) >> 1;
    down(x, l, r);
    if (L <= mid)
    {
        add_region_modify(l, mid, L, R, x << 1, add_value);
    }
    if (R > mid)
    {
        add_region_modify(mid + 1, r, L, R, (x << 1) + 1, add_value);
    }
    tree[x] = tree[x << 1] + tree[(x << 1) + 1];
    return;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }

    build(1, n, 1);

    for (int i = 1; i <= m; i++)
    {
        int temp, x, y;
        long long k;
        scanf("%d", &temp);
        if (temp == 1)
        {
            scanf("%d%d%lld", &x, &y, &k);
            add_region_modify(1, n, x, y, 1, k);
        }
        else if (temp == 2)
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}