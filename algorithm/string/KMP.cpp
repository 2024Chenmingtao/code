#include <cstring>

int next[1000];
char a[1000], b[1000]; // a.substr()=b
void make_next()
{
    int len = 0; // next
    int i = 1;
    int cnt = 0;
    while (i < strlen(b))
    {
        if (b[len] == b[i])
        {
            len++;
            cnt++;
            next[cnt] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                cnt++;
                next[cnt] = 0;
                i++;
            }
            else
            {
                len = next[len - 1];
            }
        }
    }
}
void kmp()
{
    make_next();
    int alen = strlen(a), blen = strlen(b);
    int i = 0;
    int j = 0;
    while (i < alen)
    {
        if (a[i] == b[j]) // 匹配
        {
            i++;
            j++;
        }
        else if (j > 0) // 匹配失败，字符串后移
        {
            j = next[j];
        }
        else
        {
            i++;
        }
        if (j == blen)
        {
            throw_answer(i); // 指从a[i]~a[i+j]为匹配的子串
            j = next[j];
            // j=0 用于找出所有不重复的字串
        }
    }
}
int main()
{
    scanf("%s%s",a,b);
}