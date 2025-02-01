#include <cstdio>
#include <deque>
using namespace std;
struct Node
{
    int id;
    int value;
};
int value[1000006];
deque<Node> que;
int n, k;
// 最小值

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &value[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        while (!que.empty() && que.front().id <= i - k)
        {
            que.pop_front();
        }
        while (!que.empty() && que.back().value >= value[i])
        {
            que.pop_back();
        }
        que.push_back((Node){i, value[i]});
        if (i >= k)
        {
            printf("%d ", que.front().value);
        }
    }
    que.clear();
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        while (!que.empty() && que.front().id <= i - k)
        {
            que.pop_front();
        }
        while (!que.empty() && que.back().value <= value[i])
        {
            que.pop_back();
        }
        que.push_back((Node){i, value[i]});
        if (i >= k)
        {
            printf("%d ", que.front().value);
        }
    }
}