#include <iostream>
using namespace std;

int digit(int a)
{ // 각 자릿수 더해주는 함수, 이 함숫값과 원래 값을 더하면 분해합이다.
    int sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        if (i + digit(i) == t)
        {
            cout << i << endl; // 생성자가 있는지 확인
            return 0;          // return 0 해주는게 함수를 끝내는 거 -> 이거 없으면 216의 생성자가 198, 207 둘다 나옴
        }
    }
    cout << 0 << endl;
    return 0;
}