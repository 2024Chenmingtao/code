#include <cstdio>

using namespace std;

int n;
int map[100][100];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        map[i][1] = map[i][i] = 1;
        for (int j = 2; j <= i-1; j++)
        {
            map[i][j] = map[i - 1][j] + map[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}