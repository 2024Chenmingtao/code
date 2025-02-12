#include <iostream>
using namespace std;
int a[1000010];
int ans;
int main()
{
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    a[1] = 1;
    // 筛法
    for (int i = 2; i <= n; i++)
    {
        if (!a[i])
        {
            for (int j = i; j <= n; j += i)
            {
                a[j] = i;
            }
        }
        if (a[i] <= b)
        {
            ans++;
        }
    }
    if (a[1] <= b)
    {
        ans++;
    }
    cout << ans;
    return 0;
}