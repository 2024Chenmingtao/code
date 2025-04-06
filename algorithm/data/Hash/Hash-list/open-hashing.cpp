#include <string>
#include <cstring>
// 字符串hash
class Hash
{
private:
#define SIZE 1000008
    struct Node
    {
        Node *next = nullptr;
        std::string value;
    };
    Node data[4 * SIZE]; // 节点
    Node *list[SIZE];    // 哈希表
#undef SIZE
    int data_len = 0;
    unsigned int transform(char a)
    {
        if ('0' <= a && a <= '9')
        {
            return a - '0';
        }
        else if ('A' <= a && a <= 'Z')
        {
            return a - 'A' + 10;
        }
        else
        {
            return a - 'a' + 36;
        }
    }
    unsigned long long hash(std::string s, unsigned long long mod = 10000007)
    {
        unsigned long long value = 0;
        unsigned int len = s.length();
        for (int i = 0; i < len; i++)
        {
            value = (value * 62 + transform(s[i])) % mod;
        }
        return value;
    }

public:
    void insert(std::string value)
    {
        unsigned long long hash_value = hash(value);
        data_len++;
        data[data_len].value = value;
        data[data_len].next = list[hash_value];
        list[hash_value] = &data[data_len];
    }
    bool find(std::string value)
    {
        unsigned long long hash_value = hash(value);
        Node *now = list[hash_value];
        bool flag = false;
        while (now != nullptr)
        {
            if (now->value == value)
            {
                flag = true;
                break;
            }
            now = now->next;
        }
        return flag;
    }
    Hash()
    {
        memset(list, 0, sizeof(list));
    }
};