#include <cstdio>
#include <algorithm>
using namespace std;
int a[1009];
double ans = 0;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ans += a[i];
    }
    sort(a + 1, a + n + 1);
    ans -= a[1] + a[n];
    double cnt = ans / (n - 2) * 1.0;
    printf("%.2lf", ans / (n - 2));
}