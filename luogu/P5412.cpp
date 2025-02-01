#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int T, n;
char temp;
long double input;
int main()
{
    cin >> T;
    for (int o = 1; o <= T; o++)
    {
        vector<long double> boys, girls;
        bitset<20000> flag;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            if (temp == '0')
            {
                flag[i] = false;
            }
            else
            {
                flag[i] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> input;
            if (flag[i] == true)
            {
                boys.push_back(input);
            }
            else
            {
                girls.push_back(input);
            }
        }
        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());
        for (auto b : girls)
        {
            cout << b << ' ';
        }
        cout << endl;
        for (auto a : boys)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
}