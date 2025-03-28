#include <cstdio>
#include <queue>
using namespace std;
int map[31][31], n, ans[31][31];
const int walkx[] = {-1, 1, 0, 0}, walky[] = {0, 0, -1, 1};
void bfs(int start_x, int start_y, int color)
{
    map[start_x][start_y] = color;
    queue<int> quex, quey;
    quex.push(start_x), quey.push(start_y);
    while (!quex.empty())
    {
        int x = quex.front(), y = quey.front();
        quex.pop(), quey.pop();
        for (int i = 0; i <= 3; i++)
        {
            if (((1 <= (x + walkx[i])) && ((x + walkx[i]) <= n)) && ((1 <= (y + walky[i])) && ((y + walky[i]) <= n)) && (map[x + walkx[i]][y + walky[i]] == 0))
            {
                map[x + walkx[i]][y + walky[i]] = color;
                quex.push(x + walkx[i]), quey.push(y + walky[i]);
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
            ans[i][j] = map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (map[i][1] == 0)
            bfs(i, 1, 1);
        if (map[i][n] == 0)
            bfs(i, n, 1);
        if (i > 1 && i < n)
        {
            if (map[1][i] == 0)
                bfs(1, i, 1);
            if (map[n][i] == 0)
                bfs(n, i, 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1)
            {
                printf("%d ", ans[i][j]);
                continue;
            }
            printf("2 ");
        }
        printf("\n");
    }
}