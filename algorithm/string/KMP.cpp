// 0-Base
// 字符串从0开始
#include <cstring>
#include <cstdio>
const int MAXN = 1000006;
int nxt[MAXN];
char a[MAXN], b[MAXN]; // a.substr()=b
int alen, blen;
void make_next()
{
    int j = -1; // 当前(需计算next值的位置)的前一个位置的next值
    nxt[0] = -1;
    // b[0]不需要计算，肯定为-1
    for (int i = 1; i < blen; i++)
    {
        while (j != -1 /*没有到最前面*/ && b[i] != b[j + 1] /*失配*/)
        {
            j = nxt[j]; // 往前跳
        }
        if (b[i] == b[j + 1]) // 证明找到了相等的位置，位置为j+1
        {
            j++;
        }
        nxt[i] = j; // 如果未匹配，j值自然为-1
    }
}
void kmp()
{
    make_next();
    int j = -1;
    for (int i = 0; i < alen; i++)
    {
        while (j != -1 && a[i] != b[j + 1])
        {
            j = nxt[j];
        }
        if (a[i] == b[j + 1])
        {
            j++; // 匹配位置增加一
        }
        if (j == blen - 1) // b串完全匹配
        {
            printf("%d\n", i - j + 1);
            j = nxt[j];
        }
    }
}
int main()
{
    scanf("%s%s", a, b);
    alen = strlen(a), blen = strlen(b);
    kmp();

    for (int i = 0; i < blen; i++)
    {
        printf("%d ", nxt[i] + 1);
    }
}