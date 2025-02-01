#include <cstdio>
#include <algorithm>
using std::sort;
int main()
{
    int a[3];
    char A, B, C;
    scanf("%d%d%d %c %c %c", &a[0], &a[1], &a[2], &A, &B, &C);
    sort(a, a + 3);
    if (A == 'A')
    {
        if (B == 'B')
        {
            printf("%d %d %d", a[0], a[1], a[2]);
        }
        else
        {
            printf("%d %d %d", a[0], a[2], a[1]);
        }
    }
    else if (A == 'B')
    {
        if (B == 'A')
        {
            printf("%d %d %d", a[1], a[0], a[2]);
        }
        else
        {
            printf("%d %d %d", a[1], a[2], a[0]);
        }
    }
    else
    {
        if (B == 'A')
        {
            printf("%d %d %d", a[2], a[0], a[1]);
        }
        else
        {
            printf("%d %d %d", a[2], a[1], a[0]);
        }
    }
}