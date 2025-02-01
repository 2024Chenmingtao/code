#include <cstdio>
int now_money_count, month_for_no_money, give_mom_money_count;
int main()
{
    for (int month = 1; month <= 12; month++)
    {
        int this_month_money;
        now_money_count += 300;
        scanf("%d", &this_month_money);
        now_money_count -= this_month_money;
        if (now_money_count < 0)
        {
            printf("-%d", month);
            return 0;
        }
        give_mom_money_count += now_money_count / 100 * 100;
        now_money_count %= 100;
    }
    now_money_count += give_mom_money_count * 1.2;
    printf("%d", now_money_count);
}