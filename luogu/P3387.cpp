#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <set>
using namespace std;
int dfn[10009], low[10009];
int n, m, cnt = 0, oldvalue[10009], newvalue[10009], color[10009], now_color = 0;
set<int> G[10009];
set<int> map[10009];
stack<int> s;
bitset<10009> flag;
void tarjan(int id)
{
    cnt++;
    dfn[id] = low[id] = cnt;
    s.push(id);
    flag[id] = true;
    for (auto a : G[id])
    {
        if (dfn[a] == 0) // dfn==0 未被访问过
        {
            tarjan(a);
            low[id] = min(low[id], low[a]);
        }
        else if (flag[a] == true) // 自己的儿子是自己的父亲（返祖边）
        {
            low[id] = min(low[id], dfn[a]); // 有可能一个节点有很多条返祖边，选最早的祖宗
        }
    }
    if (dfn[id] == low[id])
    {
        now_color++;
        while (1)
        {
            int front = s.top();
            s.pop();
            newvalue[now_color] += oldvalue[front];
            color[front] = now_color;
            flag[front] = false;
            if (front == id)
            {
                break;
            }
        }
    }
}
void suodian()
{
    for (int i = 1; i <= n; i++)
    {
        for (auto a : G[i])
        {
            if (color[a] != color[i])
            {
                map[color[i]].insert(color[a]);
            }
        }
    }
}
void topo()
{
    queue<int> que;
    vector<int> in(now_color + 1), can(now_color + 1);
    for (int i = 1; i <= now_color; i++)
    {
        for (auto a : map[i])
        {
            in[a]++;
        }
    }
    for (int i = 1; i < in.size(); i++)
    {
        if (in[i] == 0)
        {
            can[i] = newvalue[i];
            que.push(i);
        }
    }
    while (que.empty() == false)
    {
        int front = que.front();
        que.pop();
        for (auto a : map[front])
        {
            can[a] = max(can[a], newvalue[a] + can[front]);
            in[a]--;
            if (in[a] == 0)
            {
                que.push(a);
            }
        }
    }
    int maxn = -1e9 - 7;
    for (auto a : can)
    {
        if (a > maxn)
        {
            maxn = a;
        }
    }
    printf("%d ", maxn);
}
void build(int start, int end)
{
    G[start].insert(end);
}
int main()
{
    // freopen("heak1.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &oldvalue[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int start, end;
        scanf("%d%d", &start, &end);
        build(start, end);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    suodian();
    topo();
}