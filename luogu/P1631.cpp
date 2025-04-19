#include <queue>
#include <cstdio>
#include <set>
#include <stack>
using namespace std;
set<int> a, b;
priority_queue<int> sum;
int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        a.insert(temp);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        b.insert(temp);
    }
    for (set<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        for (set<int>::iterator it2 = b.begin(); it2 != b.end(); it2++)
        {
            sum.push((*it) + (*it2));
            if (sum.size() > n)
            {
                sum.pop();
            }
        }
    }
    stack<int> stk;
    while (!sum.empty())
    {
        stk.push(sum.top());
        sum.pop();
    }
    while (!stk.empty())
    {
        printf("%d ", stk.top());
        stk.pop();
    }
}