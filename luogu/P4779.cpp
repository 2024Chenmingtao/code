#include <cstdio>
#include <queue>
using namespace std;
struct DATA
{
    int newnode = 0, value = 0;
    bool operator<(DATA other)
    {
        return this->value < other.value;
    }
};
priority_queue<DATA> que;
struct Edge
{
    int v;
    int w; // 边权
    Edge *next;
};
Edge e[200005];
int elong = 0;
Edge *head[100005];
int n, m, start;
int main()
{
    scanf("%d%d%d", &n, &m, &start);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        elong++;
        e[elong].next = head[u];
        head[u] = &e[elong];
        e[elong].v = v;
        e[elong].w = w;
    }
}