#include <iostream>
using std::cout;
using std::cin;
int main()
{
    int n;
    cin>>n;
    if(n%4==0&&n%100!=0)
    {
        printf("1");
    }
    else if(n%400==0)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}