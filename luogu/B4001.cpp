#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i * i * i <= n; i++)
    {
        if (i * i * i == n)
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}