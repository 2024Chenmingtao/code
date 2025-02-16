#include <bits/stdc++.h>
using namespace std;
int t, h;
bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return (x != 1 && x > 0 && x != 0);
}
int main()
{
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        int now = 1, i = 0;
        cin >> h;
        while (h > 0)
        {
            if (prime(h))
            {  
                cout << i + 1 << endl;
                break;
            }
            h -= now;
            i++;
            now *= 2;
        }
        if (prime(h))
        {
            continue;
        }
        else if (h < 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}