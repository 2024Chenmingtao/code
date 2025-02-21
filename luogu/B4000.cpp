#include <cstdio>
int main()
{
    int h, m, s, k;
    scanf("%d%d%d%d", &h, &m, &s, &k);
    s += k;
    // new s
    m += s / 60;
    s %= 60;
    // new m;
    h += m / 60;
    m %= 60;
    // new h
    h %= 24;
    printf("%d %d %d", h, m, s);
    return 0;
}