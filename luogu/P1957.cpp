#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int T;
short last;
char a[1000];
char answer[1000];
int main()
{
    // freopen("a.txt","r",stdin);
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        memset(answer, 0, sizeof(answer));
        cin.getline(a, 1000, '\n');
        if ('9' >= a[0] && a[0] >= '0') // 说明是上一个题目的运算方式
        {
            int st, nd;
            sscanf(a, "%d %d", &st, &nd);
            if (last == 1) // jiafa
            {
                sprintf(answer, "%d+%d=%d", st, nd, st + nd);
                printf("%s\n%d", answer, strlen(answer));
            }
            if (last == 2) // jianfa
            {
                sprintf(answer, "%d-%d=%d", st, nd, st - nd);
                printf("%s\n%d", answer, strlen(answer));
            }
            if (last == 3) // chengfa
            {
                sprintf(answer, "%d*%d=%d", st, nd, st * nd);
                printf("%s\n%d", answer, strlen(answer));
            }
        }
        else
        {
            char temp;
            int st, nd;
            sscanf(a, "%c %d %d", &temp, &st, &nd);
            if (temp == 'a')
            {
                last = 1;
                sprintf(answer, "%d+%d=%d", st, nd, st + nd);
            }
            else if (temp == 'b')
            {
                last = 2;
                sprintf(answer, "%d-%d=%d", st, nd, st - nd);
            }
            else
            {
                last = 3;
                sprintf(answer, "%d*%d=%d", st, nd, st * nd);
            }
            printf("%s\n%d", answer, strlen(answer));
        }
        printf("\n");
    }
    return 0;
}