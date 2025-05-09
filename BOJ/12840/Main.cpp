#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, m, s;
    cin >> h >> m >> s;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        char c;
        cin >> c;
        if (c == '3')
        {
            cout << h << " " << m << " " << s << '\n';
        }
        if (c == '1')
        {
            int time;
            cin >> time;
            int total;
            total = h * 3600 + m * 60 + s;
            total += time;
            total %= (24 * 3600); // 전체 시간이 하루를 넘기지 않도록 방지.
            h = total / 3600;
            total %= 3600;
            m = total / 60;
            s = total % 60;
        }
        if (c == '2') // 이건 케이스를 나눠서 하면 음수에서 60을 더해줘도 음수인 경우를 판단 못함. (여러 번 보정이 필요) 전체 시간을 초로 계산하는게 더 안전.
        {
            int time;
            cin >> time;
            int total;
            total = h * 3600 + m * 60 + s;
            total -= time;
            if (total < 0)
            {
                while (total < 0)
                {
                    total += 24 * 3600;
                }
            }
            h = total / 3600;
            total %= 3600;
            m = total / 60;
            s = total % 60;
        }
    }
}