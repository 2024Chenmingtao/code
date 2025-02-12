#include <bits/stdc++.h>
using namespace std;
int n, m, MAX = INT_MIN;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1, temp; i <= n; i++)
    {
        scanf("%d", &temp);
        MAX = max(MAX, temp);
    }
    for (int i = 1, temp; i <= m; i++)
    {
        scanf("%d", &temp);
        if (n == 1)
            MAX += temp;
        else if (temp > 0)
            MAX += temp;
    }
    printf("%d", MAX);
}