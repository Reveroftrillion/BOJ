#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    string s;
    cin >> K >> s;

    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        int P = i + 1;
        int S = 3 * P + K;

        char c = s[i];
        int x = c - 'A';

        x = (x - S % 26 + 26) % 26;

        ans += char('A' + x);
    }

    cout << ans;
}
