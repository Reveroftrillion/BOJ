#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, i, mx = 0, cnt = 0;
    cin >> N >> L;
    for (i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        int onecnt = 0;
        if (str[0] == '1')
            onecnt++;
        for (int j = 1; j < L; j++)
        {
            if (str[j - 1] == '0' && str[j] == '1')
                onecnt++;
        }

        if (mx < onecnt)
        {
            mx = onecnt;
            cnt = 0;
        }
        if (mx == onecnt)
            cnt++;
    }
    cout << mx << ' ' << cnt;
}