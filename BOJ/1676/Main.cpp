#include <iostream>
#include <string>
#include <algorithm>
using namespace std; // 팩토리얼을 전부 계산하고 0의 개수를 reverse해서 세는 건 시간초과
// 그래서 0의 개수 = 5의 개수라는 점을 이용.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int cnt = 0;
    for (int i = 5; i <= t; i *= 5) // i는 5의 제곱수만큼 늘고, 5의 배수만큼 0의 생기되, 25나 125의 배수들은 중복해서 세줘야한다.
    {
        cnt += t / i;
    }
    cout << cnt << endl;
}
