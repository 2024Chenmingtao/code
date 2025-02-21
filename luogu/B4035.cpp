#include <cstdio>
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp % 8 != 0 && temp % 9 == 0)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}