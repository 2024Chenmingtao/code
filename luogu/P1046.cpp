#include <cstdio>
int main()
{
    int a[10], x;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    x += 30;
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] <= x)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}