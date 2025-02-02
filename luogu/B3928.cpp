#include <cstdio>
#include <algorithm>
using namespace std;
int my[50009], tianji[50009];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &my[i]);
    }
    sort(my + 1, my + n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tianji[i]);
    }
    sort(tianji + 1, tianji + n + 1);
    int ans = 0, l = 1, r = 1;
    while (l <= n && r <= n)
    {
        while (true)
        {
            if (my[l] < tianji[r])
            {
                l++;
            }
            else
            {
                ans++;
                l++;
                r++;
                break;
            }
        }
    }
    printf("%d", ans);
}