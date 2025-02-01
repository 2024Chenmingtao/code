#include <cstdio>
int main()
{
    int a, i;
    scanf("%d", &a);
    for (i = 1;; i++)
    {
        if (a == 1)
        {
            break;
        }
        a /= 2;
    }
    printf("%d", i );
    return 0;
}