#include <cstdio>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        int temp = a[i], cnt = 0;
        sort(a, a + i);
        for (int j = 0; j <= i; j++)
        {
            if (a[j] < temp)
            {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }
}