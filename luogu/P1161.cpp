#include <cstdio>
#include <bitset>
using namespace std;
int main()
{
    bitset<2000001> flag;
    flag.reset();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double a;
        int t;
        scanf("%lf%d",&a,&t);
        for(int j=1;j<=t;j++)
        {
            flag[(int)(a*j)]=!flag[(int)(a*j)];
        }
    }
    for(int i=0;i<=2000000;i++)
    {
        if(flag.test(i)==true)
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}