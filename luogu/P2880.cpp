#include <iostream>
#include <cmath>
using namespace std;

template <class T, int MAXN, int LOGMAXN>
class maxst
{
private:
    T st[MAXN][LOGMAXN];
    inline T max(T x, T y)
    {
        return x > y ? x : y;
    }
    void init()
    {
        for (int j = 1; j <= (int)log2(n); j++)
        {
            for (int i = 1; i <= n - (1 << j) + 1; i++)
            {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int n;

public:
    void given_input(T a[])
    {
        for (int i = 1; i <= n; i++)
        {
            st[i][0] = a[i];
        }
        init();
        return;
    }
    void input()
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> st[i][0];
        }
        init();
    }
    T queuy(int l, int r)
    {
        int s = (int)log2(r - l + 1);
        return max(st[l][s], st[r - (1 << s) + 1][s]);
    }
    void SETN(int n)
    {
        this->n = n;
    }
};
template <class T, int MAXN, int LOGMAXN>
class minst
{
private:
    T st[MAXN][LOGMAXN];
    inline T max(T x, T y)
    {
        return x > y ? x : y;
    }
    void init()
    {
        for (int j = 1; j <= (int)log2(n); j++)
        {
            for (int i = 1; i <= n - (1 << j) + 1; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int n;

public:
    void given_input(T a[])
    {
        for (int i = 1; i <= n; i++)
        {
            st[i][0] = a[i];
        }
        init();
        return;
    }
    void input()
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> st[i][0];
        }
        init();
    }
    T queuy(int l, int r)
    {
        int s = (int)log2(r - l + 1);
        return min(st[l][s], st[r - (1 << s) + 1][s]);
    }
    void SETN(int n)
    {
        this->n = n;
    }
};
int n, m, a[50004];
maxst<int, 100009, 30> stmax;
minst<int, 100009, 30> stmin;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    stmax.SETN(n);
    stmin.SETN(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    stmax.given_input(a);
    stmin.given_input(a);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << stmax.queuy(l, r) - stmin.queuy(l, r) << endl;
    }
}