#include <cstdio>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int index = a; index <= b; index++)
    {
        bool flag = true;
        for (int i = 2; i * i <= index; i++)
        {
            if (index % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            int temp = index % 10 * 10 + index / 10;
            for (int i = 2; i * i <= temp; i++)
            {
                if (temp % i == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n", index);
            }
        }
    }
    return 0;
}