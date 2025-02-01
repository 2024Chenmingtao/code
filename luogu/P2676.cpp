#include <cstdio>
#include <algorithm>
using std::sort;
int a[20009],n,ans;
long long b,cnt;
bool cmp(int x,int y)
{
    if(x>y)
    {
        return 1;
    }
    return 0;
}
int main()
{
    scanf("%d%lld",&n,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++)
    {
        cnt+=a[i];
        ans++;
        if(cnt>=b)
        {
            printf("%d",ans);
            return 0;
        }
    }

}