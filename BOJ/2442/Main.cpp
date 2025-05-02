#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - i - 1; j++) // 이게 t-1로 고정을 해버리면 5를 입력하면 무조건 공백이 4개로 됨. 나는 4,3,2,1을 원하는 거니까 i를 집어넣어야 함
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        } // 얘 뒤에 공백입력하고 줄바꿈하는 문자를 for문에 넣으면 돌 때마다 endl이 실행되니까 바로 endl하도록 만들자.
        cout << endl;
    }
}