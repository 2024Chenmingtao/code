#include <bits/stdc++.h>
using namespace std;
int n, sp[100][100];
string a[20], x;
char tt[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
struct sz
{
    int t, z;
    string s;
    char xx;
} p[10000];
void zhuan(string x, int j, int i)
{
    int sum = 0;
    if (x[1] <= '9' && x[1] >= '0')
    {
        sum += (x[1] - '0') * 1;
    }
    else
    {
        sum += (x[1] - 'A' + 10) * 1;
    }
    if (x[0] <= '9' && x[0] >= '0')
    {
        sum += (x[0] - '0') * 16;
    }
    else
    {
        sum += (x[0] - 'A' + 10) * 16;
    }
    p[sum].t++;     // 次数加一
    p[sum].s = x;   // 保留其十六进制，注意是字符串
    sp[i][j] = sum; // 保留它的十进制，方便输出
}
bool cmp(sz a, sz b)
{ // 注意判断
    if (a.t != b.t)
    {
        return a.t > b.t;
    }
    else
    {
        return a.z < b.z;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i <= 256; i++)
    {
        p[i].z = i, p[i].t = 0; // 初始化
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < a[i].size(); j += 2)
        {
            x += a[i][j], x += a[i][j + 1];
            zhuan(x, j / 2, i);
            x = "";
        }
    }
    sort(p, p + 256, cmp);
    for (int i = 0; i < 16; i++)
    {
        cout << p[i].s;
        p[i].xx = tt[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i].size() / 2; j++)
        {
            int mm = 300, wz;
            for (int q = 0; q < 16; q++)
            {
                if (abs(sp[i][j] - p[q].z) < mm)
                {
                    wz = q, mm = abs(sp[i][j] - p[q].z);
                }
            }
            cout << p[wz].xx;
        }
        cout << endl;
    }
    return 0;
}
