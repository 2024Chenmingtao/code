#include <cstdio>
// 建立栈，栈顶指针，左儿子数组，右儿子数组
const int MAXN = 10000000;
long long a[MAXN], stk[MAXN], top = 0, left[MAXN], right[MAXN];
inline long long read()
{
    long long x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    { // ch 不是数字时
        if (ch == '-')
            w = -1;     // 判断是否为负
        ch = getchar(); // 继续读入
    }
    while (ch >= '0' && ch <= '9')
    {                            // ch 是数字时
        x = x * 10 + (ch - '0'); // 将新读入的数字「加」在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar(); // 继续读入
    }
    return x * w; // 数字 * 正负号 = 实际数值
}
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
void compute_xor_values(int n)
{
    long long xor_left = 0, xor_right = 0;
    for (int i = 1; i <= n; i++)
    {
        xor_left ^= i * (left[i] + 1);
        xor_right ^= i * (right[i] + 1);
    }
    printf("%lld %lld", xor_left, xor_right);
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    work(n);
    compute_xor_values(n);
    return 0;
}