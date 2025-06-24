#include <bits/stdc++.h>
using namespace std;

int teamA[301], teamB[301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> teamA[i];
    for (int i = 0; i < n; i++)
        cin >> teamB[i];

    int cntA = 0, cntB = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if ((teamA[i] == 1 && teamB[i] == 2) ||
            (teamA[i] == 2 && teamB[i] == 3) ||
            (teamA[i] == 3 && teamB[i] == 1))
        {
            // A 승
            cntA++;
            cntB = 0;
        }
        else if ((teamB[i] == 1 && teamA[i] == 2) ||
                 (teamB[i] == 2 && teamA[i] == 3) ||
                 (teamB[i] == 3 && teamA[i] == 1))
        {
            // B 승
            cntB++;
            cntA = 0;
        }
        else
        {
            // 비김: 이전 승자 기준으로 반대팀 점수 증가
            if (cntA > 0)
            {
                cntA = 0;
                cntB = 1;
            }
            else if (cntB > 0)
            {
                cntB = 0;
                cntA = 1;
            }
            else
            {
                cntA = cntB = 1;
            }
        }

        ans = max({ans, cntA, cntB});
    }

    cout << ans << '\n';
    return 0;
}
