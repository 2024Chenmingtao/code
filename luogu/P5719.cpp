#include <iostream>
#include <cstdio>
using namespace std;
double a1, count_a1, a2, count_a2;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            count_a1++;
            a1 += i;
        }
        else
        {
            count_a2++;
            a2 += i;
        }
    }
    printf("%.1lf %.1lf", a1 / count_a1, a2 / count_a2);
}