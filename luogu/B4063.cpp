#include <cstdio>
int main()
{
    int n, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp % 2 == 0)
        {
            cnt2++;
        }
        else
        {
            cnt1++;
        }
    }
    printf("%d %d", cnt1, cnt2);
    return 0;
}