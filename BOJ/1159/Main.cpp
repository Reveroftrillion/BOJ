#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> cnt(26, 0);
    string s;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        if (!s.empty())
        {
            char c = s[0];
            if ('a' <= c && c <= 'z')
                cnt[c - 'a']++;
        }
    }

    string ans;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] >= 5)
            ans.push_back('a' + i);
    }

    if (ans.empty())
        cout << "PREDAJA\n";
    else
        cout << ans << "\n";

    return 0;
}