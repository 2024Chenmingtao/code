#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> magic(n, vector<int>(n, 0)); // 动态空间防爆

    int row = 0;
    int col = n / 2;
    magic[row][col] = 1;

    for (int num = 2; num <= n * n; ++num)
    {
        int new_row = (row - 1 + n) % n;
        int new_col = (col + 1) % n;

        if (magic[new_row][new_col] == 0)
        {
            row = new_row;
            col = new_col;
        }
        else
        {
            row = (row + 1) % n;
        }
        magic[row][col] = num;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << magic[i][j];
            if (j != n - 1) // 空格
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}