#include <iostream>
using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        int number = 1;
        int count = 1;
        while (number % n != 0) // mod 연산 사용
        {
            number = (number * 10 + 1) % n; // 모든 자릿수 계산을 하는게 아니라 나머지들로만 계산을 진행.
            count++;
        }
        cout << count << endl;
    }

    return 0;
}