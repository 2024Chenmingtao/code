#include <cstdio>
int cnt[11];
int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp != 0)
        {
            cnt[temp % 10]++;
            temp /= 10;
        }
    }
    printf("%d", cnt[x]);
}