#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main()
{
    int N;
    cin >> N;
    vector<long long> mat(N + 1);
    for (int i = 0; i < N; i++)
    {
        long long r, c;
        cin >> r >> c;
        if (i == 0)
        {
            mat[0] = r;
        }
        mat[i + 1] = c;
    }

    const long long INFINITY = (1LL << 60);
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int how_many = 2; how_many <= N; how_many++)
    {
        for (int start = 0; start + how_many - 1 < N; start++)
        {
            int end = start + how_many - 1;
            long long best = INFINITY;
            for (int k = start; k < end; k++)
            {
                long long cost = dp[start][k] + dp[k + 1][end] + mat[start] * mat[k + 1] * mat[end + 1]; // 이거 사이 끼는 거 생략이구나.
                if (cost < best)
                {
                    best = cost;
                }
            }
            dp[start][end] = best;
        }
    }
    cout << dp[0][N - 1] << endl;
    return 0;
}