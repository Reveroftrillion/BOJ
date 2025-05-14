#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        double a, b;
        cin >> a >> b;
        double answer = (2 * a) / b;
        cout.precision(2);
        cout << "The height of the triangle is " << fixed << answer << " units" << endl;
    }
}