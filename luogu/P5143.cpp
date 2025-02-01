#include <cmath>
#include <cstdio>
#include <algorithm>
using std::sort;
struct Node
{
    int x, y, z;
    bool operator<(const Node &other)const 
    {
        return z < other.z;
    }
};

Node a[50006];
double ans;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a + 1, a + n + 1);
    Node last = a[1];
    for (int i = 2; i <= n; i++)
    {
        ans += sqrt(((last.x - a[i].x) * (last.x - a[i].x)) + ((last.y - a[i].y) * (last.y - a[i].y)) + ((last.z - a[i].z) * (last.z - a[i].z)));
        last = a[i];
        // printf("%.3lf ",ans);
    }
    printf("%.3lf", ans);
    return 0;
}