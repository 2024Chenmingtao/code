#include <iostream>
using namespace std;
// 先实现区间最大值
int tree[400000], a[400000], lazy[400000]; // 四倍空间

// 下推懒标记
void down(int x)
{
    if (lazy[x]) // 如果有懒标记
    {
        // 下传左子树
        lazy[x << 1] += lazy[x];
        tree[x << 1] += lazy[x];
        // 下传右子树
        lazy[(x << 1) + 1] += lazy[x];
        tree[(x << 1) + 1] += lazy[x];
        // 清除当前节点的懒标记
        lazy[x] = 0;
    }
}
void build(int l, int r, int x) // 对[l,r]区间建立一颗以x为根的线段树
{
    if (l == r)
    {
        tree[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1; // (l+r)/2;
    // 左子树
    build(l, mid, (x << 1));
    // 右子树
    build(mid + 1, r, (x << 1) + 1);
    // 合并
    tree[x] = max(tree[(x << 1)], tree[(x << 1) + 1]);
    return;
}

int query(int L, int R /*查询区域*/, int l, int r /*当前区域*/, int x)
{
    if (L <= l && r <= R) // 找到
    {
        return tree[x];
    }
    if (lazy[x] != 0)
    {
        down(x);
    }

    int mid = (l + r) >> 1; // l+(l+r)/2;
    int ans = -1e9 - 7;
    if (L <= mid)
    {
        ans = max(ans, query(L, R, l, mid, x << 1));
    }
    if (R > mid)
    {
        ans = max(ans, query(L, R, mid + 1, r, (x << 1) + 1));
    }
    return ans;
}

void point_modify(int left, int right /*当前搜索的左右区间*/, int x /*当前在tree数组中的编号*/, int i /*目标在原数组中的编号*/, int newvalue /*需要修改的值*/)
{
    if (left == right) // 这个元素必定表示的就是[left, left]
    {
        tree[x] = newvalue;
        return;
    }
    int mid = (left + right) >> 1;
    if (i <= mid)
    {
        point_modify(left, mid, (x << 1), i, newvalue);
    }
    else
    {
        point_modify(mid + 1, right, (x << 1) + 1, i, newvalue);
    }
    tree[x] = max(tree[x << 1], tree[(x << 1) + 1]); // 更新数据
}

void add_region_modify(int l, int r /*当前区间*/, int L, int R /*需要处理的区间*/, int x /*当前节点编号*/, int add_value /*区间中每一个数需要增加的值*/)
{
    if (L <= l && r <= R) // 被完全包含
    {
        tree[x] += add_value; // 最大值增加add_value
        lazy[x] += add_value;
        return;
    }
    int mid = (l + r) >> 1;
    down(x);
    if (L <= mid)
    {
        add_region_modify(l, mid, L, R, x << 1, add_value);
    }
    if (R > mid)
    {
        add_region_modify(mid + 1, r, L, R, (x << 1) + 1, add_value);
    }
    tree[x] = max(tree[x << 1], tree[(x << 1) + 1]); // 更新当前节点的最大值
    return;
}