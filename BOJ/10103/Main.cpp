#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int c_result = 100;
    int s_result = 100;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            c_result -= b;
        }
        else if (a > b)
        {
            s_result -= a;
        }
    }
    cout << c_result << endl;
    cout << s_result << endl;
}