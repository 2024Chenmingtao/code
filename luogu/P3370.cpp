#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
bitset<1000000008> flag;
/// @brief
/// @param a
/// @return
unsigned int transform(char a)
{
    if ('0' <= a && a <= '9')
    {
        return a - '0';
    }
    else if ('A' <= a && a <= 'Z')
    {
        return a - 'A' + 10;
    }
    else
    {
        return a - 'a' + 36;
    }
}
/// @brief 字符串哈希(0-Base)
/// @param s 需要处理的字符串
/// @return 哈希值
unsigned long long HASH(char *s, unsigned long long m = 1000000007)
{
    unsigned long long value = 0;
    unsigned int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        value = (value * 62 + transform(s[i])) % m;
    }
    return value;
}
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    char a[1505];
    for (int i = 1; i <= n; i++)
    {

        memset(a, 0, sizeof(a));
        scanf("%s", a);
        unsigned long long value = HASH(a);
        if (flag[value] == false)
        {
            cnt++;
            flag[value] = true;
        }
    }
    printf("%d", cnt);
}