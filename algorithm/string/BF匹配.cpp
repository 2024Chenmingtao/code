//暴力枚举进行字符串匹配
#include <string>
using namespace std;
bool find(string a,string b)
{
    for(int i=0;i<a.size();i++)
    {
        bool flag=false;
        for(int j=0;j<b.size();j++)
        {
            if(a[i+j]!=b[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            printf("found");
        }
    }
}