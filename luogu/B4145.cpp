#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, k, maxn = 0, cnt = 0;
    cin >> x >> y >> k;
    for (int b = 0; b <= x; b++)
    {
        for (int p = 1; p <= y; p++)
        {
            for (int z = 0; z <= k; z++)
            {
                if (((b + p) ^ (z)) == maxn)
                {
                    cnt++;
                }
                if (((b + p) ^ (z)) > maxn)
                {
                    maxn = (b + p) ^ z;
                    cnt = 1;
                }
            }
        }
    }
    cout << maxn << endl;
    cout << cnt;
    return 0;
}