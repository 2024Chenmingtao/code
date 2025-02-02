#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
    int id;
    int value;
} cnt[300];

bool cmp(Node x, Node y)
{
    return x.value > y.value;
}

int n, map[30][30], ans[30][30], a[30], stringlen;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char temp[100];
        int k;
        scanf("%s", temp);
        stringlen = strlen(temp);
        for (int j = 0; j < strlen(temp); j++)
        {

            if (j % 2 == 0)
            {
                k = ('0' <= temp[j] && temp[j] <= '9') ? (temp[j] - '0') : (temp[j] - 'A');
                k *= 10;
            }
            if (j % 2 != 0)
            {
                k += ('0' <= temp[j] && temp[j] <= '9') ? (temp[j] - '0') : (temp[j] - 'A');
                map[i][j / 2] = k;
                cnt[k].value++;
                cnt[k].id = k;
            }
        }
    }
    sort(cnt, cnt + 256, cmp);
    for (int i = 0; i < 16; i++)
    {
        a[i] = cnt[i].id;
    }
    sort(a, a + 16);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < stringlen / 2; j++)
        {
            int maxn = 1e9 + 7;
            for (int index = 0; index < 16; index++)
            {
                if (abs(map[i][j] - a[index]) < maxn)
                {
                    maxn = abs(map[i][j] - a[index]);
                    ans[i][j] = a[index];
                }
            }
            printf("%c", (ans[i][j]<10)?ans[i][j]+'0':ans[i][j]-10+'A');
        }
        printf("\n");
    }
}