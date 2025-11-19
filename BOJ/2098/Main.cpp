#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> city(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int k;
            cin >> k;
            city[i][j] = k;
        }
    }

    int start = 0;     // 시작 도시
    int full = 1 << N; // 비트마스크의 전체 경우의 수

    vector<vector<long long>> dp(full, vector<long long>(N, 10000001));
    // dp[mask][i] : 방문 여부, i 도시에 있을 때 최소 비용
    dp[1][0] = 0;

    for (int mask = 0; mask < full; mask++)
    {
        for (int i = 0; i < N; i++)
        {
            if (dp[mask][i] == 10000001)
                continue;
            for (int j = 0; j < N; j++)
            {
                if (mask & (1 << j))
                    continue; // 이미 방문했으면 패스
                              // 둘 다 1이어야 1 되니까
                if (city[i][j] == 0)
                    continue;
                int next = mask | (1 << j);                    // j번째 도시까지 방문으로 만듦
                long long possible = dp[mask][i] + city[i][j]; // 지금까지 든 비용 + 가는 비용
                if (possible < dp[next][j])                    // 원래 계산한 것보다 작으면 갱신
                {
                    dp[next][j] = possible;
                }
            }
        }
    }

    long long answer = 10000001;
    int all = full - 1;

    for (int i = 0; i < N; i++)
    {
        if (dp[all][i] == 10000001)
            continue;
        if (city[i][start] == 0)
            continue;
        long long cost = dp[all][i] + city[i][start];
        if (cost < answer)
        {
            answer = cost;
        }
    }
    cout << answer << endl;
}