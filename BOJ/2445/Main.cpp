#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i < t + 1; i++) // 문자열 반복 시, python 처럼 "*" * i 이런 방법 X ;; string(i, '*') 이런 방법 사용해야함
    {
        cout << string(i, '*') << string(2 * (t - i), ' ') << string(i, '*') << endl;
    }
    for (int i = t - 1; i > 0; i--)
    {
        cout << string(i, '*') << string(2 * (t - i), ' ') << string(i, '*') << endl;
    }
}