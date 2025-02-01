#include <cstdio>
bool a[100][100][100];
int main()
{
    int w, xq, h, q;
    scanf("%d%d%d%d", &w, &xq, &h, &q);
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                for (int z = z1; z <= z2; z++)
                {
                    a[x][y][z] = true;
                }
            }
        }
    }
    long long ans = 0;
    for (int x = 1; x <= w; x++)
    {
        for (int y = 1; y <= xq; y++)
        {
            for (int z = 1; z <= h; z++)
            {
                if (a[x][y][z] == false)
                {
                    ans++;
                }
            }
        }
    }
    printf("%lld", ans);
}