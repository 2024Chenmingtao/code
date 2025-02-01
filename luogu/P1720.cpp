#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c=0,num=0;
	cin>>num;
	a=b=1;//初始值为1
	for(int i=3;i<=num;++i){
		c=b+a;//算第个数
		a=b;//b的值赋给a
		b=c;//c的值赋给b 
	} 
	cout<<c<<".00";
	return 0;
}
