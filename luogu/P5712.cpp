#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x == 1 || x == 0)
    {
        cout << "Today, I ate "<<x<<" apple.";
    }
    if (x >= 2)
    {
        cout << "Today, I ate " << x << " apples.";
    }
    return 0;
}