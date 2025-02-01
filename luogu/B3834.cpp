#include <cstdio>
int A;
int main()
{
    int cnt = 0;
    scanf("%d", &A);
    for (int i = 1; i * i <= A; i++)
    {
        if ((int)(A / i) * i == A)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
}