#include <iostream>
#include <vector>
using namespace std; // 이 문제에서 sort랑 vector<long long> 쓰면 메모리 초과 // 그래서 10000까지 있는 벡터를 설정하고 들어올때마다 count를 늘리는 식으로 풀자.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> number(10001, 0);
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        number[k]++;
    }
    for (int i = 1; i < 10001; i++)
    {
        while (number[i] > 0)
        {
            cout << i << '\n';
            number[i]--;
        }
    }
}