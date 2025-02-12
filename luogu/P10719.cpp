#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + (grid[i][j] == '1' ? 1 : 0);
        }
    }

    int total_black = pre[n][m];
    if (total_black < k)
    {
        cout << 0 << endl;
        return 0;
    }

    int min_area = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int sum_total = pre[j + 1][m] - pre[i][m];
            if (sum_total < k)
                continue;

            vector<int> cols;
            for (int c = 0; c < m; ++c)
            {
                int val = pre[j + 1][c + 1] - pre[i][c + 1] - (pre[j + 1][c] - pre[i][c]);
                cols.push_back(val);
            }

            int left = 0, current_sum = 0, min_col_len = INT_MAX;
            for (int right = 0; right < m; ++right)
            {
                current_sum += cols[right];

                while (current_sum >= k && left <= right)
                {
                    int window_len = right - left + 1;
                    if (window_len < min_col_len)
                    {
                        min_col_len = window_len;
                    }
                    current_sum -= cols[left];
                    left++;
                    if (left > right)
                        break;
                }
            }

            if (min_col_len != INT_MAX)
            {
                int area = (j - i + 1) * min_col_len;
                if (area < min_area)
                {
                    min_area = area;
                }
            }
        }
    }

    cout << (min_area != INT_MAX ? min_area : 0) << endl;

    return 0;
}