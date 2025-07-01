#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 숫자판은 읽기만 하고 사용하지 않는다.
    for (int i = 0, x; i < N * N; ++i)
        cin >> x;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << i + 1 << (j + 1 == N ? '\n' : ' ');
    }
    return 0;
}
