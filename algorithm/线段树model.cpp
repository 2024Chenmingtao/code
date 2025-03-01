#include <cstdio>

// 返回两个整数中的较大值
const int max(int a, int b)
{
    return a > b ? a : b;
}

int a[100001]; // 原始数组，最多存储100000个元素
int t[400021]; // 线段树数组，大小为4*100000+21以保证足够空间
int n, m;      // n：数组元素个数，m：操作次数

// 构建线段树
// left, right: 当前区间的左右边界
// x: 当前节点在线段树数组中的索引
void build(int left, int right, int x)
{
    if (left == right)
    { // 叶子节点，直接赋值
        t[x] = a[left];
        return;
    }
    int middle = (left + right) / 2;
    build(left, middle, x * 2);          // 递归构建左子树
    build(middle + 1, right, x * 2 + 1); // 递归构建右子树
    t[x] = max(t[x * 2], t[x * 2 + 1]);  // 当前节点值为左右子树最大值
}

// 修改数组中的某个值，并更新线段树
// left, right: 当前区间的左右边界
// x: 当前节点索引
// L: 要修改的位置（原始数组中的下标）
// R: 新的值
void modify(int left, int right, int x, int L, int R)
{
    if (left == right)
    { // 找到目标位置，更新值
        t[x] = R;
        return;
    }
    int middle = (left + right) / 2;
    if (L <= middle)
    { // 目标在左子树
        modify(left, middle, x * 2, L, R);
    }
    else
    { // 目标在右子树
        modify(middle + 1, right, x * 2 + 1, L, R);
    }
    t[x] = max(t[x * 2], t[x * 2 + 1]); // 更新父节点的最大值
}

// 查询区间[L, R]的最大值
// left, right: 当前区间的左右边界
// x: 当前节点索引
// L, R: 查询区间的左右边界（原始数组下标）
int query(int left, int right, int x, int L, int R)
{
    if (left == L && right == R)
    { // 当前区间完全匹配查询区间
        return t[x];
    }
    int middle = (left + right) / 2;
    if (R <= middle)
    { // 查询区间完全在左子树
        return query(left, middle, x * 2, L, R);
    }
    if (L > middle)
    { // 查询区间完全在右子树
        return query(middle + 1, right, x * 2 + 1, L, R);
    }
    // 查询区间跨越左右子树，分别查询后取最大值
    return max(
        query(left, middle, x * 2, L, middle),
        query(middle + 1, right, x * 2 + 1, middle + 1, R));
}

int main()
{
    int z, x, y;
    scanf("%d", &n); // 读取数组长度
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]); // 读取数组元素
    }
    build(1, n, 1); // 构建线段树，根节点索引为1

    scanf("%d", &m); // 读取操作次数
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &z, &x, &y);
        if (z == 1)
        { // 修改操作：将a[x]的值改为y
            modify(1, n, 1, x, y);
        }
        else
        { // 查询操作：输出区间[x,y]的最大值
            printf("%d\n", query(1, n, 1, x, y));
        }
    }
}