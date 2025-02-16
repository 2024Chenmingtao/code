    #include <cstdio>
    const char g[4][4] = {
        {'0', '0', '0', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '0', '0'}};
    char c[100][100];
    bool check(int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (c[i + x][j + y] != g[i][j])
                {
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    int n, m, t;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    scanf(" %c", &c[i][j]);
                }
            }
            bool flag = false;
            for (int i = 1; i <= n - 3; i++)
            {
                for (int j = 1; j <= m - 3; j++)
                {
                    if (check(i, j))
                    {
                        flag = true;
                    }
                }
            }
            printf("%s\n", flag ? "Yes" : "No");
        }
    }