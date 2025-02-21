#include <iostream>
#include <cmath>
struct Node
{
    int ax, ay, az, bx, by, bz;
} a, b;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a.ax >> a.ay >> a.az 
        >> a.bx >> a.by >> a.bz 
        >> b.ax >> b.ay >> b.az 
        >> b.bx >> b.by >> b.bz;
    int x,y,z;

    //x
    if(max(a.ax,b.ax)>min(a.bx,b.bx))
    {
        cout<<0;
        return 0;
    }
    x=min(a.bx,b.bx)-max(a.ax,b.ax)+1;
    
    //y
    if(max(a.ay,b.ay)>min(a.by,b.by))
    {
        cout<<0;
        return 0;
    }
    y=min(a.by,b.by)-max(a.ay,b.ay)+1;
    
    //z
    if(max(a.az,b.az)>min(a.bz,b.bz))
    {
        cout<<0;
        return 0;
    }
    z=min(a.bz,b.bz)-max(a.az,b.az)+1;


    cout<<x*y*z;
    return 0;
}