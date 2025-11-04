#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long Modulo = 1000000000LL;
const int BIT_MASK = 0b1111111111; // 비트마스크는 2진수로 동작하니 1 << 10 - 1 또는 이렇게 사용한다.

// 비트마스크 쓰는 문제 -> BOJ 2098을 풀어볼 것.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N < 10)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));
    // dp[length][last][mask]
    // length : 현재 길이
    // last : 마지막으로 사용한 숫자
    // mask : 어떤 숫자들이 쓰였는지 비트로 표시하는 용도.

    // dp[1][3][0000001000] = 1으로 두면서 0000001000 = 3이 한 번 나왔다고 써주기.
    // length가 1인 것들은 전부 채워두기.
    for (int i = 1; i < 10; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    for (int length = 1; length < N; length++)
    {
        for (int last = 0; last < 10; last++)
        {
            for (int mask = 0; mask <= BIT_MASK; mask++)
            {
                // 가능한 계단수의 갯수
                long long stair_number_num = dp[length][last][mask];
                if (stair_number_num == 0)
                    continue;

                // 다음 수가 last - 1인 경우
                if (last - 1 >= 0)
                {
                    int next = last - 1;
                    // OR 연산으로 비트마스크를 최신화한다.
                    int update = mask | (1 << next);
                    // length가 1 늘어난 dp에 갯수 더해주기
                    // length가 2, last가 3이고, dp[2][3][mask] = 5라고 하면 stair_number_num = 5니까 가능한 계단수의 갯수가 5
                    // 여기에 계단수 유지하려면 2나 4만 올 수 있으니 그게 붙으면 계단수가 5개씩 는다는 거니까 덧셈해주기.
                    dp[length + 1][next][update] = (dp[length + 1][next][update] + stair_number_num) % Modulo;
                }
                // 다음 수가 last + 1인 경우
                if (last + 1 <= 9)
                {
                    int next = last + 1;
                    int update = mask | (1 << next);
                    dp[length + 1][next][update] = (dp[length + 1][next][update] + stair_number_num) % Modulo;
                }
            }
        }
    }

    long long answer = 0;
    for (int last = 0; last < 10; last++)
    {
        answer = (answer + dp[N][last][BIT_MASK]) % Modulo;
    }
    cout << answer << endl;
    return 0;
}