#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a[100];
bool cmp(string &x, string &y)
{
    return x + y > y + x;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
}