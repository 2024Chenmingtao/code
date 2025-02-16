#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
vector<long long> a[1005];
long long check(int tar)
{
    long long sum = 0, now = a[1].size();
    vector<long long> temp;
    for (int i = 2; i <= n; i++)
        if (!a[i].empty())
        {
            int numi = max((int)a[i].size() - tar + 1, 0);
            now += numi;
            for (int j = 0; j <= numi - 1; j++)
            {
                sum += a[i][j];
            }
            for (int j = numi; j <= (int)a[i].size() - 1; j++)
            {
                temp.push_back(a[i][j]);
            }
        }
    if (now < tar)
    {
        sort(temp.begin(), temp.end());
        for (auto ele : temp)
        {
            sum += ele;
            now++;
            if (now == tar)
            {
                break;
            }
        }
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, c;
        cin >> p >> c;
        a[p].push_back(c);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!a[i].empty())
        {
            sort(a[i].begin(), a[i].end());
        }
    }
    long long ans = 1e18;
    for (int i = max((int)a[1].size(), 1); i <= m; i++)
    {
        ans = min(ans, check(i));
    }
    cout << ans;
    return 0;
}