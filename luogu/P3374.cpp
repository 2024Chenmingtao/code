/*树状数组实现单点修改，区间查询*/
#include <cstdio>
#define MAXN 500006
int a[MAXN] /*原数组*/, tree[MAXN] /*新数组*/, n /*数的多少*/, m;
// x 的二进制中，最低位的 1 以及后面所有 0 组成的数。
int lowbit(int x)
{
    return ((x) & ((-1) * x));
}

// a[1]..a[x]的和,类似前缀和
int getsum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += tree[x];
        x -= lowbit(x) /*自己能管辖到的区间*/; // 下一个管辖不到的区间
    }
    return ans;
}
// 获取a~b的区间和
int queuy(int a, int b)
{
    return getsum(b) - getsum(a - 1);
}
// 单点增加，a[x]+=k
void add(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        add(i, tmp);
    }
    for (int i = 1; i <= m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1)
        {
            int x, k;
            scanf("%d%d", &x, &k);
            add(x, k);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", queuy(x, y));
        }
    }
    return 0;
}