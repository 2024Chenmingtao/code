#include <iostream>
template <class T>
class Segment_Tree
{
private:
    T tree[100000], a[100000];
    void build(int l, int r, int x) // 对[l,r]区间建立一颗以x为根的线段树
    {
        if (l == r)
        {
            tree[x] = a[l];
            return;
        }
        int mid = (l + (l + r) >> 1); // l+(l+r)/2;
        // 左子树
        build(l, mid, (x << 2));
        // 右子树
        build(mid + 1, r, (x << 2) + 1);
        // 合并
        tree[x] = max(tree[(x << 2)], tree[(x << 2) + 1]);
        return;
    }
    long long query(int L, int R /*查询区域*/, int l, int r /*当前区域*/, int x)
    {
        if (l <= l && r <= R)
        {
            return tree[x];
        }
        int mid = (l + (l + r) >> 1); // l+(l+r)/2;
        T ans = 0;
        if (L <= mid)
        {
            ans = max(ans, query(L, R, L, mid, x << 2));
        }
        if (R > mid)
        {
            ans = max(ans, query(L, R, mid + 1, r, (x << 2) + 1));
        }
        return ans;
    }
    void point_modify(int left, int right /*当前搜索的左右区间*/, int x /*当前在tree数组中的编号*/, int i /*目标在原数组中的编号*/, T newvalue /*需要修改的之*/)
    {
        if (left == right) // 这个元素必定表示的就是[left, left]
        {
            tree[left] = newvalue return;
        }
        int mid = (left + right) / 2;
        if (i <= mid)
        {
            modify(left, mid, x * 2, i, newvalue);
        }
        else
        {
            modify(mid + 1, left, x * 2 + 1, i, newvalue)
        }
        tree[x] = max(tree[x * 2], tree[x * 2 + 1]); // 更新数据
    }
    void modify(int l,int r)
public:
};
