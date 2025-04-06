#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
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
unsigned long long hash(char *s, unsigned long long m = 1000000007)
{
    unsigned long long value = 0;
    unsigned int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        value = (value * 62 + transform(s[i])) % m;
    }
    return value;
}
/// @brief 字符串哈希(0-Base)
/// @param s 需要处理的字符串
/// @return 哈希值
unsigned long long hash(string s, unsigned long long m = 1000000007)
{
    unsigned long long value = 0;
    unsigned int len = s.length();
    for (int i = 0; i < len; i++)
    {
        value = (value * 62 + transform(s[i])) % m;
    }
    return value;
}