#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<int>> a;
string word;
int n, l, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        for (int j = 1; j <= l; j++)
        {
            cin >> word;
            a[word].insert(i);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> word;
        for (auto it = a[word].begin(); it != a[word].end(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }
}