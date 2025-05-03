#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << endl;
    string ca, cb, str;
    ca = to_string(a); // 이걸 원래는 int값에 48을 더해서 char로 바꾸는 방식을 썼는데, 이러면 0부터 9까지 밖에 못해서
    cb = to_string(b); // 런타임 에러가 발생. 그래서 처음부터 ca, cb를 string으로 받고 int를 string으로 바꿈.
    str = ca + cb;
    int d;
    d = stoi(str);
    cout << d - c << endl;
}