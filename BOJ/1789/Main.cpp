#include <iostream>
using namespace std;

int main()
{
    long long num;
    cin >> num;
    long long sum = 0;
    long long i = 1;
    while (num >= i)
    {
        num -= i;
        sum++;
        i++; // num -= i와 i++ 순서가 반대로 되면 첫 루프부터 1이 아닌 2를 빼는 경우가 생긴다.
    }

    cout << sum << endl;
}