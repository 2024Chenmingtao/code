#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    if (a + b <= c)
    {
        cout << "Not triangle";
        return 0;
    }
    if (a * a + b * b == c * c)
    {
        cout << "Right triangle" << endl;
    }
    if (a * a + b * b > c * c)
    {
        cout << "Acute triangle" << endl;
    }
    if (a * a + b * b < c * c)
    {
        cout << "Obtuse triangle" << endl;
    }
    if (a == b || a == c || b == c)
    {
        cout << "Isosceles triangle" << endl;
    }
    if (a == b && b == c)
    {
        cout << "Equilateral triangle" << endl;
    }
    return 0;
}