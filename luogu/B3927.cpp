#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    int N;
    cin >> N;
    unordered_map<string, string> dict;
    for (int i = 0; i < N; ++i)
    {
        string a, b;
        cin >> a >> b;
        dict[a] = b;
    }
    string S;
    cin >> S;
    string res;
    string temp;
    for (auto c : S)
    {
        if (c >= 'a' && c <= 'z')
        {
            temp += c;
        }
        else
        {
            if (!temp.empty())
            {
                auto it = dict.find(temp);
                if (it != dict.end())
                {
                    res += it->second;
                }
                else
                {
                    res += "UNK";
                }
                temp.clear();
            }
            res += c;
        }
    }
    if (!temp.empty())
    {
        auto it = dict.find(temp);
        if (it != dict.end())
        {
            res += it->second;
        }
        else
        {
            res += "UNK";
        }
    }
    cout << res << endl;
    return 0;
}