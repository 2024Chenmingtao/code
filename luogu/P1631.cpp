#include <cstdio>
#include <set>
using namespace std;
int n;
const int MAXN = 100005;
int a[MAXN], b[MAXN];
set<int> answer;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; (i - 1) * (j - 1) <= n && j <= n; j++)
        {
            answer.insert(a[i] + b[j]);
        }
    }
    auto it = answer.begin();
    for (int i = 1; i <= n; i++, it++)
    {
        printf("%d ", *it);
    }
    return 0;
}