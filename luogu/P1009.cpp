#include <iostream>
using namespace std;
int main()
{
    unsigned long long n = 0, s = 0, t = 1;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        t *= i;
        s += t;
    }
    cout << s;
}