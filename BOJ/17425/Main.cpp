#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector<long long> g(MAX + 1);      // 약수들의 합
vector<long long> prefix(MAX + 1); // 그걸 미리 더해두기 위함

void precompute()
{
    for (int i = 1; i <= MAX; ++i)
    {
        for (int j = i; j <= MAX; j += i) // i를 약수로 가지는 j들에게 미리 i만큼 더해줌, 시간 복잡도가 O(N log N) 이다.
        {
            g[j] += i;
        }
    }
    for (int i = 1; i <= MAX; ++i)
    {
        prefix[i] = prefix[i - 1] + g[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        cout << prefix[k] << '\n';
    }

    return 0;
}
