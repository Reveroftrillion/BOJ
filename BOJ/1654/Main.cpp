#include <iostream>
#include <vector>
using namespace std;

// 이걸 위에서부터 1씩 줄이면서 내려오면 시간 초과
// 이분탐색으로 중앙부터 검사하고 되면 그 위로, 안되면 그 아래로 검사

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    vector<long long> pt(a);
    long long high = 0;
    long long low = 1;
    long long answer = 0;

    for (int i = 0; i < a; i++)
    {
        cin >> pt[i];
        high = max(high, pt[i]);
    }

    while (low <= high)
    {
        long long middle = (low + high) / 2;
        long long count = 0;
        for (long long lenline : pt)
        {
            count += (lenline / middle);
        }
        if (count >= b)
        {
            answer = middle;
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    cout << answer << '\n';
    return 0;
}