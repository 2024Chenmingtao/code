#include <cstdio>
#define MAXN 100000
long long tree[4 * MAXN + 10], a[MAXN + 10], add_lazy[4 * MAXN + 10], mul_lazy[4 * MAXN + 10] /*乘法lazy*/;
int m;
void down(int x, int l, int r)
{
    int mid = (l + r) >> 1;
    if (mul_lazy[x] != 1)
    {
        // 更改左右子节点的值
        tree[x << 1] = (tree[x << 1] * mul_lazy[x]) % m;
        tree[(x << 1) + 1] = (tree[(x << 1) + 1] * mul_lazy[x]) % m;
        // 下推乘法标记
        mul_lazy[x << 1] = (mul_lazy[x] * mul_lazy[x << 1]) % m;
        mul_lazy[(x << 1) + 1] = (mul_lazy[x] * mul_lazy[(x << 1) + 1]) % m;
        // 把乘法标记应用到加法标记上
        add_lazy[x << 1] = (add_lazy[x << 1] * mul_lazy[x]) % m;
        add_lazy[(x << 1) + 1] = (add_lazy[(x << 1) + 1] * mul_lazy[x]) % m;
        // 恢复
        mul_lazy[x] = 1;
    }
    if (add_lazy[x] != 0)
    {
        int left_len = mid - l + 1;
        int right_len = r - mid;
        tree[x << 1] = (tree[x << 1] + (add_lazy[x] * left_len)) % m;
        add_lazy[x << 1] = (add_lazy[x << 1] + add_lazy[x]) % m;
        tree[(x << 1) + 1] = (tree[(x << 1) + 1] + add_lazy[x] * right_len) % m;
        add_lazy[(x << 1) + 1] = (add_lazy[(x << 1) + 1] + add_lazy[x]) % m;
        add_lazy[x] = 0;
    }
}
void build(int l, int r, int x)
{
    add_lazy[x] = 0;
    mul_lazy[x] = 1;
    if (l == r)
    {
        tree[x] = a[l] % m;
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
    down(x, l, r);
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

void mul_region_modify(int l, int r, int L, int R, int x, long long mul_value)
{
    if (L <= l && r <= R)
    {
        tree[x] = (tree[x] * mul_value) % m;
        mul_lazy[x] = (mul_lazy[x] * mul_value) % m;
        add_lazy[x] = (add_lazy[x] * mul_value) % m;
        return;
    }
    int mid = (l + r) >> 1;
    down(x, l, r);
    if (L <= mid)
    {
        mul_region_modify(l, mid, L, R, x << 1, mul_value);
    }
    if (R > mid)
    {
        mul_region_modify(mid + 1, r, L, R, (x << 1) + 1, mul_value);
    }
    tree[x] = (tree[x << 1] + tree[(x << 1) + 1]) % m;
    return;
}
void add_region_modify(int l, int r, int L, int R, int x, long long add_value)
{
    if (L <= l && r <= R)
    {
        tree[x] = (add_value * (r - l + 1) + tree[x]) % m;
        add_lazy[x] = (add_lazy[x] + add_value) % m;
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
    tree[x] = (tree[x << 1] + tree[(x << 1) + 1]) % m;
    return;
}
int n, q;
int main()
{
    scanf("%d%d%d", &n, &q, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, n, 1);

    for (int i = 1; i <= q; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == 1)
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            mul_region_modify(1, n, x, y, 1, k);
        }
        else if (temp == 2)
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            add_region_modify(1, n, x, y, 1, k);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1) % m);
        }
    }
}