#include <cstdio>
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cnt++;
            printf("%02d",cnt);
        }
        printf("\n");
    }   
}