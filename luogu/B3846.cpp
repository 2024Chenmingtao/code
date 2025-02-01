#include <cstdio>
int main()
{
    long long sum = 0;
    int start, end;
    scanf("%d%d", &start, &end);
    for (int i = start + 1; i <= end - 1; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
        {
            sum += i;
        }
    }
    printf("%lld", sum);
}