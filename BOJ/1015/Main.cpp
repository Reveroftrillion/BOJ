#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<pair<int, int>> v;
    v.reserve(N);
    for (int i = 0; i < N; ++i)
        v.push_back({A[i], i});

    sort(v.begin(), v.end(), [](const auto &x, const auto &y)
         {
        if (x.first != y.first) return x.first < y.first;
        return x.second < y.second; });

    vector<int> P(N);
    for (int pos = 0; pos < N; ++pos)
    {
        P[v[pos].second] = pos;
    }

    for (int i = 0; i < N; ++i)
    {
        if (i)
            cout << ' ';
        cout << P[i];
    }
    cout << '\n';
    return 0;
}
