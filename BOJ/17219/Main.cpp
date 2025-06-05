#include <bits/stdc++.h>
using namespace std;
// 처음에는 사이트랑 비밀번호 벡터 두 개로 나눠서 저장했는데 시간초과
// 쌍이고, 순서가 그리 필요 없으니까 unordered map 사용

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    unordered_map<string, string> list;
    for (int i = 0; i < a; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        list[str1] = str2;
    }
    for (int i = 0; i < b; i++)
    {
        string site;
        cin >> site;
        cout << list[site] << '\n';
    }
}