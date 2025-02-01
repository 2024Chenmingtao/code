#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
int n, m;
set<int> map[100005];
bitset<100007> vis;
void dfs(int x)
{
    printf("%d ", x);
    for (auto it = map[x].begin(); it != map[x].end(); it++)
    {
        if (vis[*it] == false)
        {
            vis[*it] = true;
            dfs(*it);
        }
    }
}
void bfs()
{
    queue<int> a;
    a.push(1);
    vis[1] = true;
    while (a.empty() == false)
    {
        printf("%d ", a.front());
        int f = a.front();
        a.pop();
        for (auto it = map[f].begin(); it != map[f].end(); it++)
        {
            if (vis[*it] == false)
            {
                a.push(*it);
                vis[*it] = true;
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x].insert(y);
    }
    vis[1]=true;
    dfs(1);
    printf("\n");
    vis.reset();
    bfs();
}