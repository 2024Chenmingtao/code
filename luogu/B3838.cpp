#include <cstdio>
int main()
{
    int h1, h2, m1, m2;
    scanf("%d%d%d%d", &h1, &m1, &h2, &m2);
    printf("%d", (h2 - h1) * 60 + (m2 - m1));
}