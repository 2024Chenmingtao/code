#include <iostream>
using namespace std;
int main()
{
    int year, month;
    cin >> year >> month;
    bool is = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    if (is)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30");
            break;
        default:
            printf("29");
            break;
        }
    }
    else
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30");
            break;
        default:
            printf("28");
            break;
        }
    }
}