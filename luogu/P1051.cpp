#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int winer_money = -9999;
string winer_name;
int money_count = 0;                  // 学生获得的奖学金的总数
string name;                          // 姓名
int Final_average_grade;              // 期末平均成绩
int Class_evaluation_score;           // 班级评议成绩
bool student_cadres;                  // 学生干部
bool Students_from_Western_Provinces; // 西部省份学生
int Number_of_papers;                 // 发表的论文数
int money;                            // 该学生获得的奖学金
int n;                                // 学生人数
char temp;                            // 临时变量

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        money = 0;
        cin >> name;
        scanf("%d%d", &Final_average_grade, &Class_evaluation_score);
        scanf(" %c", &temp);
        if (temp == 'Y')
        {
            student_cadres = true;
        }
        else
        {
            student_cadres = false;
        }
        scanf(" %c", &temp);
        if (temp == 'Y')
        {
            Students_from_Western_Provinces = true;
        }
        else
        {
            Students_from_Western_Provinces = false;
        }
        scanf("%d", &Number_of_papers);
        // 院士奖学金
        if (Final_average_grade > 80 && Number_of_papers >= 1)
        {
            money += 8000;
        }
        // 五四奖学金
        if (Final_average_grade > 85 && Class_evaluation_score > 80)
        {
            money += 4000;
        }
        // 成绩优秀奖
        if (Final_average_grade > 90)
        {
            money += 2000;
        }
        // 西部奖学金
        if (Final_average_grade > 85 && Students_from_Western_Provinces)
        {
            money += 1000;
        }
        // 班级贡献奖
        if (Class_evaluation_score > 80 && student_cadres)
        {
            money += 850;
        }
        money_count += money;
        if (money > winer_money)
        {
            winer_money = money;
            winer_name = name;
        }
    }
    cout << winer_name << endl;
    printf("%d\n%d", winer_money, money_count);
}