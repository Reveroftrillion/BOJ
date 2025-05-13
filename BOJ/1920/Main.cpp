#include <iostream>
#include <unordered_set>
using namespace std; // vector는 이렇게 큰 수에서는 사용 불가능, unordered_set 사용

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    unordered_set<long long> s;

    for (int i = 0; i < t; i++)
    {
        long long k;
        cin >> k;
        s.insert(k);
    }

    int p;
    cin >> p;

    for (int j = 0; j < p; j++)
    {
        long long q;
        cin >> q;
        if (s.count(q))
        {
            cout << "1" << '\n';
        }
        else
        {
            cout << "0" << '\n';
        }
    }
}