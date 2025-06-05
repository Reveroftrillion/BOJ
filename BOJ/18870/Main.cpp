#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> origin;
    vector<int> right;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        origin.push_back(k);
        right.push_back(k);
    }
    sort(right.begin(), right.end());
    right.erase(unique(right.begin(), right.end()), right.end()); // 이걸로 중복 제거 하는 거임

    map<int, int> press;

    for (int i = 0; i < right.size(); i++)
    {
        press[right[i]] = i; // 이러면 작은 숫자부터 0, 1, 2, 3 이렇게 키가 붙음
    }

    for (int i = 0; i < t; i++)
    {
        cout << press[origin[i]] << " ";
    }
}