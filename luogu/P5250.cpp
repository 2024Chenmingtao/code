#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
set<long long> a;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int temp;
        long long len;
        scanf("%d%lld", &temp, &len);
        if (temp == 1)
        {
            if (a.count(len))
            {
                printf("Already Exist\n");
            }
            else
            {
                a.insert(len);
            }
        }
        if (temp == 2)
        {
            if (a.empty())
            {
                printf("Empty\n");
                continue;
            }
            auto it = a.lower_bound(len);
            long long c1 = -1, c2 = -1;

            if (it != a.end())
                c1 = *it;
            if (it != a.begin())
                c2 = *prev(it);

            long long dele = -1;

            if (c1 == -1)
            {
                dele = c2;
            }
            else if (c2 == -1)
            {
                dele = c1;
            }
            else
            {
                if (abs(c1 - len) < abs(c2 - len))
                {
                    dele = c1;
                }
                else
                {
                    dele = c2;
                }
            }

            a.erase(dele);
            printf("%lld\n", dele);
        }
    }
}