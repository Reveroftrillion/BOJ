#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_palindrome(const string &s)
{
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    // equal은 인자를 a 시작, a 끝, b 시작으로 받음
    // a와 b가 같은지 확인
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> strs(N);
    int count_X = 0, count_Y = 0, overlap = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> strs[i];
        int len = strs[i].size();

        string front = strs[i].substr(0, len / 2);
        string back = strs[i].substr((len + 1) / 2);
        bool front_back_rev = (front == string(back.rbegin(), back.rend()));
        bool palindrome = is_palindrome(strs[i]);

        if (front_back_rev)
            count_X++;
        if (palindrome)
            count_Y++;
        if (front_back_rev && palindrome)
            overlap++;
    }

    // X와 Y 조건을 만족하는 서로 다른 문자열 쌍의 개수
    long long answer = 1LL * count_X * count_Y - overlap;
    cout << answer << "\n";
    return 0;
}
