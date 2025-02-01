#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s;
    int ans=0;
	for(;;)
	{
        scanf("%c",&s);
        if(s=='\n'){printf("%d",ans);return 0;}
		if(s>='A'&&s<='Z')
		ans++;
		if(s>='a'&&s<='z')
		ans++;
		if(s>='0'&&s<='9')
		ans++;
	}
	printf("%d",ans);
	return 0;
}