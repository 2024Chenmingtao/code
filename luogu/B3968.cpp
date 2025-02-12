#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    int chinese, math, english, total;
    int id;
    int rank;
    bool is_tied = false;
};

bool compare(const Student &a, const Student &b)
{
    if (a.total != b.total)
    {
        return a.total > b.total;
    }
    int sum_a = a.chinese + a.math;
    int sum_b = b.chinese + b.math;
    if (sum_a != sum_b)
    {
        return sum_a > sum_b;
    }
    int max_a = max(a.chinese, a.math);
    int max_b = max(b.chinese, b.math);
    if (max_a != max_b)
    {
        return max_a > max_b;
    }
    if (a.id != b.id)
    {
        return a.id < b.id;
    } // 保证稳定排序
    return false;
}

int main()
{
    int n;
    cin >> n;
    Student students[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
        students[i].id = i;
        students[i].rank = 0;
        students[i].is_tied = false;
    }

    sort(students, students + n, compare);

    // 标记并列的学生
    for (int i = 0; i < n - 1; ++i)
    {
        Student &a = students[i];
        Student &b = students[i + 1];
        if (a.total == b.total && (a.chinese + a.math) == (b.chinese + b.math) && max(a.chinese, a.math) == max(b.chinese, b.math))
        {
            b.is_tied = true;
        }
    }

    // 计算排名
    int current_rank = 1;
    for (int i = 0; i < n; ++i)
    {
        if (students[i].rank != 0)
        {
            continue;
        }
        students[i].rank = current_rank;
        int j = i + 1;
        while (j < n && students[j].is_tied)
        {
            students[j].rank = current_rank;
            j++;
        }
        current_rank = j - i + current_rank;
        i = j - 1; // 跳过已处理的学生
    }

    // 恢复原始顺序并输出
    sort(students, students + n, [](const Student &a, const Student &b)
         { return a.id < b.id; });

    for (const Student &s : students)
    {
        cout << s.rank << endl;
    }

    return 0;
}