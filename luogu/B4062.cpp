#include <cstdio>
int main()
{
    double k;
    scanf("%lf", &k);
    if ((1.8 * k - 459.67) > 212)
    {
        printf("Temperature is too high!");
        return 0;
    }
    printf("%.2lf %.2lf", k - 273.15, (1.8 * k - 459.67));
    return 0;
}