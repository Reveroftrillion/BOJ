#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int sum = 0;
    int num = 1; // 밖에서 초기화 해줘야지 다시 초기화 안 됨
    for (int i = 0; i < t; i++)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            sum += num;
            num += 1;
        }
        else
        {
            num = 1;
        }
    }
    cout << sum << endl;
}