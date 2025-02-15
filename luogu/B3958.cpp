#include <iostream>
#include <string>
using namespace std;
inline int abs(int x)
{
    if (x < 0)
    {
        x *= -1;
    }
    return x;
}
bool isSimilar(string a, string b)
{
    int la = a.size(), lb = b.size();
    if (abs(la - lb) > 1)
    {
        return false;
    }

    if (la == lb)
    {
        int cnt = 0;
        for (int i = 0; i < la; ++i)
        {
            if (a[i] != b[i])
            {
                cnt++;
            }
        }
        return cnt <= 1;
    }
    else
    {
        string s1 = la > lb ? a : b;
        string s2 = la > lb ? b : a;
        int i = 0, j = 0, diff = 0;
        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                diff++;
                if (diff > 1)
                {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string a, b;
        cin >> a >> b;
        if (isSimilar(a, b))
        {
            cout << "similar" << endl;
        }
        else
        {
            cout << "not similar" << endl;
        }
    }
    return 0;
}