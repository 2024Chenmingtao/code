#include <cstdio>
// 建立栈，栈顶指针，左儿子数组，右儿子数组
const int MAXN = 10000000;
long long  a[MAXN], stk[MAXN], top = 0, left[MAXN], right[MAXN];
void work(int n)
{
    // 遍历输入数组：
    for (int i = 1; i <= n; i++)
    {
        int k = top; // k:当前栈顶
        // 找到第一个节点值<=a[i]的节点
        while (k > 0 /*没有到栈顶*/ && a[stk[k]] > a[i])
        {
            k--;
        }
        // tips：此时，k指向栈中第一个满足a[stk[k]] ≤ a[i]的位置

        // 如果栈非空，证明其没有到根节点，新增节点有父亲，则把当前的节点变成父亲节点的右儿子
        if (k > 0) //<==>if(k)
        {
            right[stk[k]] = i;
        }

        // 如果弹出过节点，则要把弹出的节点变为自己的左子树
        if (k < top)
        {
            left[i] = stk[k + 1];
        }
        // 将当前节点压入栈，更新栈顶指针
        stk[k + 1] = i;
        top = k + 1;
    }
}
