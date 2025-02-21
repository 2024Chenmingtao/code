#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> a;
int main()
{
	int T;
	scanf("%d",&T);
	for(int index=1;index<=T;index++)
	{
		a.clear();
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			string temp;
			cin>>temp;
			a.push_back(temp);
		}
		sort(a.begin(),a.end());
		string temp;
		for(int i=0;i<a.size();i++)
		{
			temp+=a[i];
		}
		bool flag=true;
		for(int i=0;i<(int)temp.size()-1;i++)
		{
			if(temp[i]>temp[i+1])
			{
				flag=false;
				printf("0\n");
				break;
			}
		}
		if(flag)
		{
			printf("1\n");
		}
	}	
}