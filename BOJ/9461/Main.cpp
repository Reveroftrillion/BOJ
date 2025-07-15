#include <iostream>
using namespace std;
// 그냥 dp 돌리니까 시간 복잡도가 O(2^k)가 됨.
// 메모이제이션 사용해야한다.

long long memoization[101];

long long dp(int k)
{
    if (memoization[k] != 0)
        return memoization[k];

    if (k == 1 || k == 2 || k == 3)
        return memoization[k] = 1;
    if (k == 4 || k == 5)
        return memoization[k] = 2;

    return memoization[k] = dp(k - 1) + dp(k - 5);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        cout << dp(k) << endl;
    }
}