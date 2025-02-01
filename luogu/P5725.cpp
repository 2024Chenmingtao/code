#include <cstdio>
int main()
{
    int n, cnt = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%02d", cnt);
            cnt++;
        }
        printf("\n");
    }
    printf("\n");
    cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%02d", cnt);
            cnt++;
        }
        printf("\n");
    }
    return 0;
}