#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	int t;
	cin>>t>>a;
	while(t--)
	{
		int k,b,c;
		string d;
		cin>>k;
		if(k==1)
		{
			cin>>d;
			a+=d;
			cout<<a<<endl; 
		}
		if(k==2)
		{
			cin>>b>>c;
			string e=a;
			a="";
			for(int i=b;i<(e.length(),b+c);i++)
			a+=e[i];
			cout<<a<<endl;
		}
		if(k==3)
		{
			cin>>b>>d;
			string x="";
			for(int i=0;i<b;i++)
			x+=a[i];
			x+=d;
			for(int i=b;i<a.length();i++)
			x+=a[i];
			a=x;
			cout<<a<<endl;
		}
		if(k==4)
		{
			cin>>d;
			if(a.find(d)<100)  //因为find有时会返回奇奇怪怪的数,所以要特判
			cout<<a.find(d)<<endl;
			else
			cout<<-1<<endl;
		}
	}
	return 0;
}