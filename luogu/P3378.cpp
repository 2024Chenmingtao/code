#include <cstdio>
#include <queue>
using namespace std;
priority_queue<long long> que;
int main()
{
    int n;
    scanf("%d", &n);
    for (int index = 1; index <= n; index++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            long long x;
            scanf("%lld", &x);
            que.push(-1 * x);
        }
        else if (op == 2)
        {
            printf("%lld\n", -1 * que.top());
        }
        else
        {
            que.pop();
        }
    }
    return 0;
}