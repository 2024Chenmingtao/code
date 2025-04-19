#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<bitset<50010>> a(n + m + 1);
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp <= n)
        {
            a[i][temp] = true;
            temp += i;
        }
    }
    for (int i = n + 1; i <= n + m; i++)
    {
        int input;
        int x, y;
        scanf("%d", &input);
        if (input == 1)
        {
            scanf("%d%d", &x, &y);
            a[i] = a[x] | a[y];
        }
        else if (input == 2)
        {
            scanf("%d%d", &x, &y);
            a[i] = a[x] & a[y];
        }
        else
        {
            scanf("%d", &x);
            a[i] = a[x] ^ a[1];
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (a[x][y])
        {
            printf("TAK\n");
        }
        else
        {
            printf("NIE\n");
        }
    }
    return 0;
}
