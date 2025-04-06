#include <string>
#include <cstring>
#include <queue>
using namespace std;

class ac
{
private:
    // 字典树结构
    int son[100000][26];
    int fail[100000];
    bool exist[100000];
    int cnt;
    void trie_insert(char *s)
    {
        int p = 0;
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (son[p][c] == 0)
            {
                cnt++;
                son[p][c] = cnt;
            }
            p = son[p][c];
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
            if (!son[p][c])
            {
                return false;
            }
            p = son[p][c];
        }
        return exist[p];
    }

    /// @brief 判断节点p是否有儿子字符c
    /// @param p 需要判断的节点
    /// @param c 儿子字符编号
    /// @return true 表示有 false表示没有
    bool trie_find(int p, int c)
    {
        return (son[p][c] != 0);
    }

public:
    ac()
    {
        memset(exist, false, sizeof(exist));
        memset(fail, 0, sizeof(fail));
        memset(son, 0, sizeof(son));
    }
    /// @brief 插入模式串
    /// @param s 需要插入的模式串
    void insert(char *s)
    {
        trie_insert(s);
    }
    void build()
    {
        queue<int> q;
        q.push(0);
        // 将根节点的子节点入队
        for (int i = 0; i < 26; i++)
        {
            if (son[0][i])
            {
                q.push(son[0][i]);
            }
        }
        // 按层序遍历
        while (!q.empty())
        {
            int temp = q.front(); // temp:当前节点的父节点
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                // son[temp][i]:当前处理节点
                if (son[temp][i])
                {
                    fail[son[temp][i]] = son[fail[temp]][i]; // 让(当前节点的fail指针)指向((它父节点的fail指针)指向的节点)的儿子
                    // 使用一种类似并查集的方法，建立虚节点，节约时间
                    q.push(son[temp][i]);
                }
                else
                {
                    son[temp][i] = son[fail[temp]][i]; // 构造虚节点，指向父节点的fail指针指向的节点的儿子
                }
            }
        }
    }
};