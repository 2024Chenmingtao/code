#include <cstdio>
int main()
{
    double s, now = 2.00, cnt = 0;
    long long step = 0;
    scanf("%lf", &s);
    while (cnt <= s)
    {
        cnt += now;
        now *= 0.98;
        step++;
    }
    printf("%lld", step);
}