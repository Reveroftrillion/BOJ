#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std; // 나이 기준으로 오름차순, 동일 시 원래 들어온 순서 유지 = stable_sort 사용

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;
    vector<pair<int, string>> person; // 한 번에 두 쌍을 정렬

    for (int i = 0; i < t; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        person.push_back({age, name});
    }

    stable_sort(person.begin(), person.end(), [](const pair<int, string> &a, const pair<int, string> &b)
                {
                    return a.first < b.first; // &쓰는 이유는 주소만 복사해와서 복사 비용이 줄어듦. a와 b의 첫번째 원소만 비교해 오름차순으로 비교하고, 같으면 원래 순서 유지
                });

    for (int i = 0; i < t; i++)
    {
        cout << person[i].first << " " << person[i].second << endl;
    }
}