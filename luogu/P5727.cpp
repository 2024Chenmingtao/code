#include <cstdio>
#include <vector>
using std::vector;
vector<int> a;
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=1)
    {
        a.push_back(n);
        if(n%2==0)
        {
            n/=2;
        }
        else
        {
            n*=3;
            n+=1;
        }
    }
    printf("1 ");
    for(auto it = a.rbegin();it!=a.rend();it++)
    {
        printf("%d ",*it);
    }
    return 0;
}