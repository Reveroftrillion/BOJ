#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double A, B;
    A = ((double)c - (double)a) / (d - b);
    B = ((double)e - (double)a) / (f - b);
    if (A == B)
    {
        cout << "WHERE IS MY CHICKEN?" << endl;
    }
    else
    {
        cout << "WINNER WINNER CHICKEN DINNER!" << endl;
    }
}