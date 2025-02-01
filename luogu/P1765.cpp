#include <iostream>
#include <string>
using namespace std;

string a;
int map[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int main()
{
    int cnt = 0;
    getline(cin,a, '\n');
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ')
        {
            cnt++;
        }
        else if (a[i] >= 'a' && a[i] <= 'z')
        {
            cnt += map[a[i] - 'a'];
        }
    }
    printf("%d", cnt);
}