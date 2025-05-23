#include <iostream>
#include <unordered_map>
using namespace std;
// 벡터 쓰면 시간초과 난다.
// 전체 복잡도가 O(n)이라서 그런듯.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    long long sum = 0;           // 현재 원소들의 합
    int xorsum = 0;              // 현재 원소들의 XOR
    unordered_map<int, int> cnt; // 각 숫자의 개수

    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int number;
            cin >> number;
            cnt[number]++;
            sum += number;
            xorsum ^= number;
        }
        else if (k == 2)
        {
            int number;
            cin >> number;
            if (cnt[number] > 0)
            {
                cnt[number]--;
                sum -= number;
                xorsum ^= number; // 이미 xor해둔 걸 다시 xor하면 그 전 값으로 돌아간다.
            }
        }
        else if (k == 3)
        {
            cout << sum << '\n';
        }
        else if (k == 4)
        {
            cout << xorsum << '\n';
        }
    }
}