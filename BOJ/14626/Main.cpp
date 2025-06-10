#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s; // 13글자 문자열
    int star = -1;
    for (int i = 0; i < 13; ++i)
        if (s[i] == '*')
            star = i;

    auto weight = [&](int idx)
    { return (idx % 2 == 0) ? 1 : 3; };

    int sum = 0;
    for (int i = 0; i < 13; ++i)
    {
        if (i == star)
            continue;
        sum += weight(i) * (s[i] - '0');
    }
    sum %= 10;

    // star 자리에 들어갈 숫자 찾기
    for (int x = 0; x <= 9; ++x)
    {
        int total = (sum + weight(star) * x) % 10;
        if (total == 0)
        {
            cout << x << '\n';
            return 0;
        }
    }
}
