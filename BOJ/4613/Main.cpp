#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    while (true)
    {
        if (!getline(cin, str))
            break;
        if (str == "#")
            break;

        long long ans = 0;
        for (int i = 0; i < (int)str.size(); ++i)
        {
            int pos = i + 1;
            int val = (str[i] == ' ') ? 0 : (str[i] - 'A' + 1);
            ans += 1LL * pos * val;
        }
        cout << ans << '\n';
    }
    return 0;
}
