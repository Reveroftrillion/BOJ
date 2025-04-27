#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(10) << (double)a / b << endl;
    // 소수점 9자리 이상 출력해야해서, fixed로 소수점 이하 자리수를 고정하고
    // setprecision(10)으로 10번째 자리까지 출력하도록 만든다. (double)을 통해 소수점 나눗셈임을 말한다.
}