#include <cstdio>
long long cnt[10];
void chai(long long t)
{
    while (t != 0)
    {
        cnt[t % 10]++;
        t /= 10;
    }
    return;
}
int main()
{
    long long l, r;
    scanf("%lld%lld", &l, &r);
    for (long long i = l; i <= r; i++)
    {
        chai(i);
    }
    printf("%lld", cnt[2]);
}