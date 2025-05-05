#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, k, ans = 0;
vector<int> a;
bool check(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return (x != 1 && x != 0);
}
void dfs(int index, int choose, int sum)
{
    if (choose == k)
    {
        if (check(sum))
        {
            ans++;
        }
        return;
    }
    if (index >= n)
    {
        return;
    }
    dfs(index + 1, choose + 1, sum + a[index]);
    dfs(index + 1, choose, sum);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
    }
    dfs(0, 0, 0);
    printf("%d", ans);
}