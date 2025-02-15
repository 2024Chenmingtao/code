#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[1000006];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int answer = 0, now = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= now)
        {
            now++;
        }
        else
        {
            continue;
        }
    }
    printf("%d", now - 1);
}