#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    int oddRowCnt = 0;
    for (int i = 1; i <= r; ++i)
    {
        string w;
        cin >> w;
        int blank = c - (int)w.size();

        int left;
        if (blank % 2 == 0)
        {
            left = blank / 2;
        }
        else
        {
            ++oddRowCnt;
            if (oddRowCnt % 2 == 1)
                left = blank / 2;
            else
                left = blank / 2 + 1;
        }
        cout << string(left, '.') << w << string(blank - left, '.') << '\n';
    }
    return 0;
}
