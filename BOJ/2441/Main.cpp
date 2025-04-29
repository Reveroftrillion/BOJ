#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int i = a; i != 0; i--)
    { // 0이 되기 전까지 반복하는 for문이라서 i != 0이 조건문에 들어가야지.
        for (int k = 0; k < a - i; k++)
        { // i는 점점 줄어들거고 이게 input과의 차이를 낼테니 빈칸은 a-i 보다 작을때까지 반복
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}