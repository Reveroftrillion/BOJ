#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt[26] = {0};
    for (char c : s)
    {
        cnt[c - 'a']++;
    }

    bool all_even = true;
    bool all_odd = true;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] % 2 == 0)
            all_odd = false;
        else
            all_even = false;
    }

    if (all_even)
        cout << "0\n";
    else if (all_odd)
        cout << "1\n";
    else
        cout << "0/1\n";

    return 0;
}
