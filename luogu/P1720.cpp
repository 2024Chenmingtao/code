#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c=0,num=0;
	cin>>num;
	a=b=1;//��ʼֵΪ1
	for(int i=3;i<=num;++i){
		c=b+a;//��ڸ���
		a=b;//b��ֵ����a
		b=c;//c��ֵ����b 
	} 
	cout<<c<<".00";
	return 0;
}
