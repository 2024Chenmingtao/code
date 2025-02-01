#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    if (5 * n < 11 + 3 * n)
    {
        printf("Local");
    }
    else
    {
        printf("Luogu");
    }
    
}