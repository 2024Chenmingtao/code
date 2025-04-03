#include <string>
#include <cstring>
#include <queue>
using namespace std;

class ac
{
private:
    //字典树结构
    int tree[100000][26];
    bool exist[100000];
    int cnt;
    void trie_insert(char *s)
    {
        int p = 0;
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (tree[p][c] == 0)
            {
                cnt++;
                tree[p][c] = cnt;
            }
            p = tree[p][c];
        }
        exist[p] = true;
    }
    bool trie_find(char *s)
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
        return exist[p];
    }

    /// @brief 判断节点p是否有儿子字符c
    /// @param p 需要判断的节点
    /// @param c 儿子字符编号
    /// @return true 表示有 false表示没有
    bool trie_find(int p, int c)
    {
        return (tree[p][c]!=0);
    }

public:
    ac()
    {
        memset(exist, false, sizeof(exist));
        memset(tree, 0, sizeof(tree));
    }
    /// @brief 插入模式串
    /// @param s 需要插入的模式串
    void insert(char *s)
    {
        trie_insert(s);
    }
    void make_fail()
    {
        queue<int> a;
        a.push(0);
        
    }
};