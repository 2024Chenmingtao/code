#include <iostream>
#include <string>
using namespace std;

string first, mid, last;

void dg(string first, string mid)
{
    if (first.empty())
    {
        return;
    }
    char root = first[0];
    int RootID = mid.find(root);
    first.erase(first.begin());
    string left_fisrt = first.substr(0, RootID);
    string left_mid = mid.substr(0, RootID);
    string right_first = first.substr(RootID);
    string right_mid = mid.substr(RootID + 1);
    dg(left_fisrt, left_mid);
    dg(right_first, right_mid);
    cout << root;
}

int main()
{
    // faster io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // read string;
    cin >> mid >> first;
    dg(first, mid);
}