/*树状数组实现单点修改，区间查询*/
#include <cstdio>
class tree
{
private:
    int tree[1000] /*树状数组,填自己所需的值*/;

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

public:
    // 单点增加，a[x]+=k
    void add(int x, int k)
    {
        while (x <= n)
        {
            tree[x] += k;
            x += lowbit(x);
        }
    }

    // 获取a~b的区间和，b>=a
    int queuy(int a, int b)
    {
        return getsum(b) - getsum(a - 1);
    }
};
int n;
tree a;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        a.add(i, tmp);
    }
}