#include <cstdio>
#include <algorithm>
using namespace std;
int q, n, a[1000];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        sort(a + l, a + r+1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
}