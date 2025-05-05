#include <iostream>
using namespace std;
double cost[10005]; // 代表第i度电的花费
int inputA;
double b;
int main()
{
    int i;
    cin >> inputA;
    for (i = 1; i <= 150; i++)
        cost[i] = 0.4463;
    for (i = 151; i <= 400; i++)
        cost[i] = 0.4663;
    for (i = 401; i <= 10000; i++)
        cost[i] = 0.5663;
    for (i = 1; i <= inputA; i++)
        b += cost[i];
    b = int((b * 10) + 0.5) / 10.0;
    cout << b << endl;
    return 0;
}