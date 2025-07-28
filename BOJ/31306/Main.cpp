#include <iostream>
using namespace std;

char vowel[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt = 0;
    int yCnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        for (char c : vowel)
        {
            if (s[i] == c)
            {
                if (c == 'y')
                    yCnt++;
                cnt++;

                break;
            }
        }
    }

    cout << cnt - yCnt << ' ' << cnt << '\n';

    return 0;
}