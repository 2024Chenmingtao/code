#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::sort;
using std::endl;
struct Node 
{
    string name;
    int year,month,day,id;
    bool operator<(const Node &other)const 
    {
        if(year<other.year)
        {
            return true;//先比年
        }
	    else if(year>other.year)
        {
            return false;
        }
	    else 
	    {
		    if(month<other.month)
            {
                return true;//再比月
            }
            else if(month>other.month)
            {
                return false;
            }
            else 
            {
			    if(day<other.day)
                {
                    return true;//再比日
                }
                else if(day>other.day)
			    {
                    return false;
                }
                else
			    {
			    	if(id>other.id)
                    {
                        return true;//最后比编号
                    }
			    	else 
                    {
                        return false;
                    }
			    }
		    }
	    }
    }
};

Node a[150];
int year;
int main()
{
    cin>>year;
    for(int i=1;i<=year;i++)
    {
        cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
        a[i].id=i;
    }
    sort(a+1,a+year+1);
    for(int i=1;i<=year;i++)
    {
        cout<<a[i].name<<endl;
    }
}