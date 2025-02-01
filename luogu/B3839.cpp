#include <cstdio>
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i1 = 1, i2 = n; i1 <= n; i1++, i2--)
    {
        sum += i1 * i2;
    }
    printf("%d", sum);
}