#include <iostream>
#include <string>
using namespace std;

int main()
{
    int slen;
    string s;
    int cnt[128] = {0};
    int ans = 0;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> slen >> s;
    for (auto &l : s)
    {
        if (l == 'S' || l == 'L')
            cnt[l]++;
        else if (l == 'K')
        {
            if (cnt['S'])
                cnt['S']--, ans++;
            else
                break;
        }
        else if (l == 'R')
        {
            if (cnt['L'])
                cnt['L']--, ans++;
            else
                break;
        }
        else
            ans++;
    }

    cout << ans;
}