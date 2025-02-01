#include <cstdio>
using namespace std;
int main()
{
	int max=-1e9-7,min=1e9+7;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t>max)
		{
			max=t;
		}
		if(t<min)
		{
			min=t;
		}
	}
	printf("%d",max-min);
}
