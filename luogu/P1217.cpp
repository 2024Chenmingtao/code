#include <cstdio>
#include <vector>
using namespace std;
int inputA,b;
bool palindrome(int x)
{
	int t=x,temp=0;
	while(t!=0)
	{
		temp=temp*10+t%10;
		t/=10;
	}
	if(temp==x)
	{
		return true;
	}
	return false;
}
bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
bool check(int i)
{
	if((1000<=i&&i<=9999)||(100000<=i&&i<=999999)||(i%2==0))
	{
		return false;
	}
	if(!palindrome(i))
	{
		return false;
	}
	if(!prime(i))
	{
		return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&inputA,&b);
	for(int i=inputA;i<=b;i++)
	{
		if(check(i))
		{
			printf("%d\n",i);
		}
	}
}
