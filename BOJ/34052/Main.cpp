#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d;
    e = 1800 - a - b - c - d;
    if (e >= 300)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}