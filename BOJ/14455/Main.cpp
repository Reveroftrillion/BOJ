#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> last;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        string name;
        int milk;
        cin >> name >> milk;
        last[name] += milk;
    }

    int M = 1e9;                                         // 10억 더 쉽게 표현, 그냥 자체로는 double이나 int로 형 변환
    for (auto it = last.begin(); it != last.end(); it++) // map의 처음부터 끝까지를 뜻하는 for 문
        M = min(M, it->second);
    if (last.size() < 7)
        M = 0;

    int MM = 1e9;
    for (auto it = last.begin(); it != last.end(); it++)
    {
        if (it->second == M)
            continue;
        MM = min(MM, it->second); // value에 접근하기 위함
    }

    int cnt = 0;
    string ans = "";
    for (auto it = last.begin(); it != last.end(); it++)
    {
        if (it->second == MM)
        {
            cnt++;
            ans = it->first;
        }
    }

    if (cnt == 1)
        cout << ans << '\n';
    else
        cout << "Tie" << '\n';
    return 0;
}