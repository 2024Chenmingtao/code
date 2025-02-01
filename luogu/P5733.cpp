#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        if ('a' <= a[i] && a[i] <= 'z')
        {
            a[i] = a[i] - 'a' + 'A';
        }
    }
    cout << a;
}