#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

class MySet
{
private:
    int father[50009];

public:
    int find(int x)
    {
        if (father[x] == x)
        {
            return x;
        }
        father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y)
    {
        father[find(x)] = find(y);
    }
    bool is(int x, int y)
    {
        if (find(x) == find(y))
        {
            return true;
        }
        return false;
    }
    MySet()
    {
        for (int i = 1; i <= 50008; i++)
        {
            father[i] = i;
        }
        return;
    }
};

map<string, int> find_id;
map<int, string> find_name;
string father, son, findname;
MySet set;
int main()
{
    char c;
    int count = 1, father_id, son_id;
    while (1)
    {
        scanf(" %c", &c);
        if (c == '$')
        {
            break;
        }
        if (c == '#')
        {
            cin >> father;
            auto it = find_id.find(father);
            if (it == find_id.end())
            {
                father_id = count;
                father_id = count;
                find_id[father] = count;
                find_name[count] = father;
                count++;
            }
            else
            {
                father_id = find_id[father];
            }
        }
        if (c == '+')
        {
            cin >> son;
            auto it = find_id.find(son);
            if (it == find_id.end())
            {
                find_name[count] = son;
                find_id[son] = count;
                son_id = count;
                count++;
            }
            else
            {
                son_id = find_id[son];
            }
            set.merge(son_id, father_id);
        }
        if (c == '?')
        {
            cin >> findname;
            string returnname;
            returnname = find_name[set.find(find_id[findname])];
            cout << findname << ' ' << returnname << endl;
        }
    }
    return 0;
}