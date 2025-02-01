#include <cstdio>
#include <vector>
using std::vector;
vector<int> ans;
int main()
{
    while (1)
    {
        int t;
        scanf("%d", &t);
        if (t == 0)
        {
            break;
        }
        ans.push_back(t);
    }
    auto it = ans.rbegin();
    for (; it != ans.rend(); it++)
    {
        printf("%d ", *it);
    }
    return 0;
}