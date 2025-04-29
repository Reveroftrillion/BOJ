#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int sa1 = 0;
    int sa2 = 0;
    int sa3 = 0;
    int sa4 = 0;
    int axis = 0;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 || b == 0)
        {
            axis++;
        }
        else if (a > 0 && b > 0)
        {
            sa1++;
        }
        else if (a < 0 && b > 0)
        {
            sa2++;
        }
        else if (a < 0 && b < 0)
        {
            sa3++;
        }
        else if (a > 0 && b < 0)
        {
            sa4++;
        }
    }
    cout << "Q1: " << sa1 << endl;
    cout << "Q2: " << sa2 << endl;
    cout << "Q3: " << sa3 << endl;
    cout << "Q4: " << sa4 << endl;
    cout << "AXIS: " << axis << endl;
}