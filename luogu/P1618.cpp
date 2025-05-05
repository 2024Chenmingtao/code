#include <cstdio>
#include <bitset>
using namespace std;
int inputA, inputB, inputC;
bitset<10> visit;
bool flag = false;
int main()
{
    scanf("%d%d%d", &inputA, &inputB, &inputC);
    for (int a = 100; a <= 999; a++)
    {
        int b = (a / inputA) * inputB;
        int c = (a / inputA) * inputC;
        if (b >= 1000 || c >= 1000 || b < 100 || c < 100)
        {
            continue;
        }
        visit.reset();
        visit[a % 10] = visit[a % 100 / 10] = visit[a / 100] = true;
        visit[b % 10] = visit[b % 100 / 10] = visit[b / 100] = true;
        visit[c % 10] = visit[c % 100 / 10] = visit[c / 100] = true;
        visit.flip();
        visit[0]=false;
        if (visit.any())
        {
            continue;
        }
        printf("%d %d %d\n", a, b, c);
        flag = true;
    }
    if (flag == false)
    {
        printf("No!!!");
    }
}