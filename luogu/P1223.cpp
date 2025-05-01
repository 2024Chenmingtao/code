#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct Node
{
    int value, index;
    bool operator<(Node other)
    {
        return value < other.value;
    }
} a[1000009];
int main()
{
    scanf("%d", &n);
    for (int index = 1; index <= n; index++)
    {
        a[index].index = index;
        scanf("%d", &a[index].value);
    }
    sort(a + 1, a + n + 1);
    double sum = 0;
    for (int index = 1; index <= n; index++)
    {
        printf("%d ", a[index].index);
        sum += a[index].value * (n - index);
    }
    sum /= n;
    printf("\n%.2lf", sum);
    return 0;
}