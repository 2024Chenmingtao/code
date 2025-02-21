#include <cstdio>
int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if ((y - x + n) % n < n - (y - x + n) % n)
    {
        printf("Clockwise Loop");
    }
    else if ((y - x + n) % n == n - (y - x + n) % n)
    {
        printf("\"Wonderful\"");
    }
    else
    {
        printf("Counter-clockwise Loop");
    }
    return 0;
}