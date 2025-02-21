#include <cstdio>
int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    printf("%d", (((x + (n % 7)) % 7) ? ((x + (n % 7)) % 7) : 7));
}