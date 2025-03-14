#include <cstdio>
#include <stack>
using namespace std;
typedef int newtype;
newtype a[100000];
int left[], right[], stk[], top = 0;
void work() // 处理第x个数
{
    // stk 维护笛卡尔树中节点对应到序列中的下标
    for (int i = 1; i <= n; i++)
    {
        int k = top; // top 表示操作前的栈顶，k 表示当前栈顶
        while (k > 0 && a[stk[k]] > a[i])
        {
            k--; // 维护右链上的节点
        }
        if (k)
        {
            right[stk[k]] = i; // 栈顶元素.右儿子 -> 当前元素
        }
        if (k < top)
        {
            left[i] = stk[k + 1]; // 当前元素.左儿子 -> 上一个被弹出的元素
        }
        stk[++k] = i; // 当前元素入栈
        top = k;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
}