#include <cstdio>
int main()
{
    int h, m, s;
    char APM;
    scanf("%d%d%d %c", &h, &m, &s, &APM);
    long long ans = 0;
    if (APM == 'P')
    {
        ans += 43200;
    }
    ans += (h * 60 * 60) + m * 60 + s;
    printf("%lld", ans);
}