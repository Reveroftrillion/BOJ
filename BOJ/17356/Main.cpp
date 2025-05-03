#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    double m = (b - a) / 400.0; // double 이라고 해도 정수끼리의 나눗셈만 적어놓으면 default가 int라 int로 된다.
    double wook = pow(10, m);
    double wookje = 1.0 / (1 + wook);
    cout.precision(15);
    cout << wookje << endl;
}