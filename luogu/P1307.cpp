#include <cstdio>
int main()
{
	int t,sum=0;
	bool fu=true,zero=true;
	scanf("%d",&t);
	if(t<0)
	{
		fu=false;
		t*=-1;
	}
	while(t!=0)
	{
		sum=sum*10+t%10;
		t/=10;
	}
	if(fu==false)
	{
		printf("-");
	}
	printf("%d",sum);
}

