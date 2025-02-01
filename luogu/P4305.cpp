#include <cstdio>
#include <bitset>
#include <vector>
using std::bitset;
using std::vector;
class MySet
{
private:
    vector<long long> a;
    bitset<55555> flag;

public:
    void clear()
    {
        a.clear();
        flag.reset();
        return;
    }
    void input(int k)
    {
        a.reserve(k - 10);
        return;
    }
    void insert(long long x)
    {
        if (flag[x] == false)
        {
            flag[x] = true;
            a.push_back(x);
        }
        return;
    }
    void print()
    {
        for (int i = 0; i < a.size(); i++)
        {
            printf("%lld ", a[i]);
        }
        printf("\n");
        return;
    }
};

MySet a;

int main()
{
    // freopen("a.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        a.input(n);
        for (int j = 1; j <= n; j++)
        {
            long long t;
            scanf("%lld", &t);
            a.insert(t);
        }
        a.print();
        a.clear();
    }
    return 0;
}