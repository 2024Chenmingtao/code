#include <cstdio>
int main()
{
    int max = -1, daly = 0;
    for (int i = 1; i <= 7; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x + y > 8)
        {
            if (x + y > max)
            {
                max = x + y;
                daly = i;
            }
        }
    }
    printf("%d", daly);
    return 0;
}