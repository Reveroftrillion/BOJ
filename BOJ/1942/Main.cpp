#include <iostream>
#include <string>
using namespace std;

int second(string &time)
{
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));
    return hour * 3600 + minute * 60 + second;
}

int makestring(int time)
{
    int hour = time / 3600;
    time %= 3600;
    int minute = time / 60;
    time %= 60;
    int second = time;
    return hour * 10000 + minute * 100 + second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;

        int start = second(str1);
        int finish = second(str2);
        int cnt = 0;

        while (true)
        {
            if (makestring(start) % 3 == 0)
            {
                cnt++;
            }

            if (start == finish)
            {
                break;
            }

            start = (start + 1) % 86400;
        }
        cout << cnt << '\n';
    }
}