#include <cstdio>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
    {
        printf("31");
    }
    else if (b == 2)
    {
        printf("%d", ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) ? 29 : 28);
    }
    else
    {
        printf("30");
    }
    return 0;
}