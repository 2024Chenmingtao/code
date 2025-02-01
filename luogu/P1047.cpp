#include <cstdio>
int l, m;
bool flag[100009];
int main()
{
    scanf("%d%d", &l, &m);
    for (int i = 1; i <= m; i++)
    {
        int left, right;
        scanf("%d%d", &left, &right);

        for (int j = left; j <= right; j++)
        {
            flag[j] = true;
        }
    }
    unsigned int ans = 0;
    for (int i = 0; i <= l; i++)
    {
        if (flag[i] == false)
        {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}