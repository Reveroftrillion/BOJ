#include <iostream>
using namespace std;
// 이걸 그리디 방법으로 풀었는데 이러면 최소 방법을 찾을 수 없음.
// 그리디 방법은 매 순간 가장 좋아보이는 방법으로 선택하는 것.
// 빠르고 간단하지만, 항상 최적의 정답을 찾아주지는 않는다.
// 여기서는 DP (Dynamic Programming)을 사용하자.

int dp[1000001];

int qpqp(int k)
{
    if (k == 1)
        return 0;

    if (dp[k] != 0)
        return dp[k];

    int result = qpqp(k - 1);

    if (k % 2 == 0)
    {
        result = min(result, qpqp(k / 2));
    }
    if (k % 3 == 0)
    {
        result = min(result, qpqp(k / 3));
    }
    dp[k] = result + 1;
    return dp[k];
}

int main()
{
    int n;
    cin >> n;
    cout << qpqp(n) << endl;
}