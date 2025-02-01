#include <cstdio>
#include <set>
using namespace std;
int n;
int cnt[10];
int main()
{
    set<int> standard;
    scanf("%d", &n);
    for (int i = 1; i <= 7; i++)
    {
        int t;
        scanf("%d", &t);
        standard.insert(t);
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= 7; j++)
        {
            int t;
            scanf("%d", &t);
            if (standard.find(t) != standard.end())
            {
                ans++;
            }
        }
        switch (ans)
        {
        case 1:
            cnt[6]++;
            break;
        case 2:
            cnt[5]++;
            break;
        case 3:
            cnt[4]++;
            break;
        case 4:
            cnt[3]++;
            break;
        case 5:
            cnt[2]++;
            break;
        case 6:
            cnt[1]++;
            break;
        case 7:
            cnt[0]++;
            break;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", cnt[i]);
    }
}