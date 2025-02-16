#include <iostream>
#include <cstdio>
using namespace std;
int calculate_digit_sum(long long number)
{
    int sum = 0;
    for (; number != 0; number /= 10)
    {
        sum += number % 10;
    }
    return sum;
}
int transform_digit(long long number)
{
    number *= 7;
    while (number > 9)
    {
        number = calculate_digit_sum(number);
    }
    return number;
}
bool check_number(long long original_number)
{
    int total_sum = 0;
    int digit_position = 1;
    for (long long temp = original_number; temp != 0; temp /= 10, ++digit_position)
    {
        int current_digit = temp % 10;
        if (digit_position % 2 == 1)
        {
            total_sum += transform_digit(current_digit);
        }
        else
        {
            total_sum += current_digit;
        }
    }
    return total_sum % 8 == 0;
}
int main()
{
    int test_case_count;
    long long number;
    cin >> test_case_count;
    for (int i = 0; i < test_case_count; ++i)
    {
        cin >> number;
        bool check_result = check_number(number);
        cout << (check_result ? 'T' : 'F') << endl;
    }
    return 0;
}