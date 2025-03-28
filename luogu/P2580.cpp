#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class tire
{
private:
#define MAXN 500010
    int tree[MAXN][26];
    bool exist[MAXN];

#undef MAXN
public:
    char check[500010];
    int cnt;
    int pi;

    /// @brief 插入字符串函数
    /// @param s 待插入的字符数组指针
    void insert(const char *s)
    {
        int p = 0;
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (tree[p][c] == 0)
            {
                tree[p][c] = ++cnt;
            }
            p = tree[p][c];
        }
        exist[p] = true;
    }

    /// @brief 查找字符串函数，完全匹配
    /// @param s 待查找的字符数组指针
    /// @return true表示字符串存在，false表示不存在
    bool find(const char *s)
    {
        int p = 0;
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!tree[p][c])
            {
                return false;
            }
            p = tree[p][c];
        }
        if (exist[p])
        {
            pi = p;
            check[p]++;
            check[p] = min(2, (int)check[p]);
        }
        return exist[p];
    }
    tire()
    {
        memset(exist, false, sizeof(exist));
        memset(tree, 0, sizeof(tree));
        memset(check, false, sizeof(check));
    }
};
tire work;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        work.insert(temp.c_str());
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string temp;
        cin >> temp;
        if (work.find(temp.c_str()))
        {
            if (work.check[work.pi] == 1)
            {
                cout << "OK\n";
            }
            else
            {
                cout << "REPEAT\n";
            }
        }
        else
        {
            cout << "WRONG\n";
        }
    }
}