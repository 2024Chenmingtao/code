#include <cstdio>

int main()
{
    int k, l, r, cnt = 0;
    scanf("%d%d%d", &k, &l, &r);
    for (int i = l; i <= r; i++)
    {
        if ((i % 10 == k) || (i % k == 0))
        {
            cnt += i;
        }
    }
    printf("%d", cnt);
}