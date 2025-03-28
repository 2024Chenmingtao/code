#include <string>
#include <cstring>
using namespace std;
class tire
{
private:
    // nex数组：Trie树的节点数组，每个节点有26个子节点（对应a-z）
    // tree[p][c]表示节点p的第c个子节点的编号（c为字母序号，0-25对应a-z）
    // 初始时nex全为0，表示无子节点
    // 预设最大节点数为100000，可根据实际情况调整
    int tree[100000][26];

public:
    // cnt：当前节点的计数，初始为0，根节点编号为0，后续新节点从1开始递增
    int cnt;

    // exist数组：标记以某节点为结尾的字符串是否存在，即是否为某个插入字符串的末尾
    bool exist[100000];

    /// @brief 插入字符串函数
    /// @param s 待插入的字符数组指针
    void insert(char *s)
    {
        int p = 0;                  // 从根节点（编号0）开始遍历
        int l = strlen(s);          // 字符串长度
        for (int i = 0; i < l; i++) // 遍历字符串的每个字符
        {
            int c = s[i] - 'a'; // 将字符转换为0-25的索引（假设输入为小写字母）
            if (tree[p][c] == 0) // 如果当前字符对应的子节点不存在
            {
                tree[p][c] = ++cnt; // 创建新节点，cnt递增作为新节点编号
            }
            p = tree[p][c]; // 移动指针p到子节点，继续处理下一个字符
        }
        exist[p] = true; // 字符串处理完毕，标记末尾节点存在
    }

    /// @brief 查找字符串函数，完全匹配
    /// @param s 待查找的字符数组指针
    /// @return true表示字符串存在，false表示不存在
    bool find(char *s)
    {
        int p = 0;         // 从根节点开始遍历
        int l = strlen(s); // 字符串长度
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a'; // 字符转换为索引
            if (!tree[p][c])     // 若当前字符路径不存在
            {
                return false; // 字符串不存在，直接返回false
            }
            p = tree[p][c]; // 移动到子节点继续查找
        }
        return exist[p]; // 检查末尾节点是否被标记为存在
    }
    tire()
    {
        memset(exist,false,sizeof(exist));
        memset(tree,0,sizeof(tree));
    }
};