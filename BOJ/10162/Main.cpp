#include <iostream>
using namespace std;

int main()
{
    long long minute;
    cin >> minute;
    int but_a = 0, but_b = 0, but_c = 0;
    if (minute % 300 != 0 && minute % 60 != 0 && minute % 10 != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        but_a = minute / 300;
        minute -= (minute / 300) * 300; // 빼주는 건 몫에다가 300초를 곱해준 거

        if (minute <= 0)
        {
            cout << but_a << " " << 0 << " " << 0 << endl;
        }
        else
        {
            but_b = minute / 60; // 빼주는 건 몫에다가 60초를 곱해준 거
            minute -= (minute / 60) * 60;
            if (minute <= 0)
            {
                cout << but_a << " " << but_b << " " << 0 << endl;
            }
            else
            {
                but_c = minute / 10;
                cout << but_a << " " << but_b << " " << but_c << endl;
            }
        }
    }
}
