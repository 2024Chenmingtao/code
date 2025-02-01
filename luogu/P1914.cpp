#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string a;
    cin >> n >> a;
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = 'a' + (a[i] - 'a' + n) % 26;
    }
    cout << a;
}