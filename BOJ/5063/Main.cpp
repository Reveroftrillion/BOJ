#include <iostream>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c;
        d = b - c;
        if (a < d)
        {
            cout << "advertise" << endl;
        }
        else if (a == d)
        {
            cout << "does not matter" << endl;
        }
        else
        {
            cout << "do not advertise" << endl;
        }
    }
}