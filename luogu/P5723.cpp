#include <cstdio>
int main()
{
    unsigned long long cnt = 0, ans = 0;
    int l;
    scanf("%d", &l);
    if (l < 2)
    {
        printf("0\n");
        return 0;
    }
    if (l == 2)
    {
        printf("2\n2");
        return 0;
    }
    for (int i = 2; i <= l; i++)
    {
        bool flag = false;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cnt += i;
            if (cnt > l)
            {
                printf("%d", ans);
                return 0;
            }
            ans++;
            printf("%d\n", i);
        }
    }
}