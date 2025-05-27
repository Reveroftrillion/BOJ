#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 벡터 사용하면 find를 매번 사용해야하고 이러면 O(N)을 M만큼 사용하게 되어 시간초과가 발생한다.
// 이름 받았을 때 번호로 바꾸는 거를 O(1)로 바꾸려면 unordered_map을 사용하자.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<string> pokemon(a);
    unordered_map<string, int> mp;
    mp.reserve(a);

    // 1) 이름 → 인덱스 매핑
    for (int i = 0; i < a; i++)
    {
        cin >> pokemon[i];
        mp[pokemon[i]] = i + 1; // 1-based index
    }

    // 2) 쿼리 처리
    while (b--)
    {
        string q;
        cin >> q;

        if (!q.empty() && isdigit(static_cast<unsigned char>(q[0])))
        {
            // 숫자 입력 → 이름 출력
            int idx = 0;
            // 숫자 받아온 걸 하나씩 나눠서 index로 변환
            // 123들어오면 1 --> 12 --> 123 이런식으로.
            for (char c : q)
                idx = idx * 10 + (c - '0');
            cout << pokemon[idx - 1] << '\n';
        }
        else
        {
            // 이름 입력 → 번호 출력
            cout << mp[q] << '\n';
        }
    }
}
