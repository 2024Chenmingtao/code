#include <cstdio>
using namespace std;
bool prime(int i)
{
	for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				return false;
				break;
			}
		}
		return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i*i<=n;i++)
	{
		bool flag=false;
		if(n%i!=0)
		{
			continue;
		}
		
		if(prime(i)&&prime(n/i))
		{
			printf("%d",n/i);
			return 0;
		}
	}
}

