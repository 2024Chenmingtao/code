#include <cstdio>
using namespace std;

int main()
{
    int x, y, z, q;
    scanf("%d%d%d%d", &x, &y, &z, &q);
    if (2 * x + 5 * y + 3 * z < q)
    {
        printf("Yes\n%d", q - 2 * x - 5 * y - 3 * z);
    }
    else
    {
        printf("No\n%d", 2 * x + 5 * y + 3 * z - q);
    }
    return 0;
}