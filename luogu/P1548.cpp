#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int x1 = 1; x1 <= n - 1; x1++)
    {
        for (int y1 = 1; y1 <= n - 1; y1++)
        {
            for (int x2 = x1 + 1; x2 <= n; x2++)
            {
                for (int y2 = y1 + 1; y2 <= n; y2++)
                {
                    if((x2-x1)==(y2-y1))
                    {
                        
                    }
                }
            }
        }
    }
}