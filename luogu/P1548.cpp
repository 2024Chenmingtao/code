#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cnt = 0, ans = 0;
    cin >> n >> m;
    for (int x1 = 1; x1 <= m; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = x1; x2 <= m; x2++)
            {
                for (int y2 = y1; y2 <= n; y2++)
                {
                    if ((x2 - x1) == (y2 - y1))
                    {
                        cnt++;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d %d", cnt, ans);
}