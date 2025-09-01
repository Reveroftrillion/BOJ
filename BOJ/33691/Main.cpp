#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;
// 원래 했던 벡터는 시간초과 (O(N^2) 라서)
// list와 unordered_map, unordered_set을 사용

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N;
    list<string> lru_list;
    unordered_map<string, list<string>::iterator> lru_map;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        auto it = lru_map.find(str);

        if (it != lru_map.end())
        {
            lru_list.erase(it->second);
        }

        lru_list.push_back(str);
        lru_map[str] = --lru_list.end();
        // 리스트의 맨 마지막에서 한 칸 앞에 있는 자리를 map에 업데이트.
    }
    vector<string> name_of_used_program(lru_list.begin(), lru_list.end());

    reverse(name_of_used_program.begin(), name_of_used_program.end());
    cin >> K;
    unordered_set<string> pinned_list;
    for (int j = 0; j < K; j++)
    {
        string pin;
        cin >> pin;
        pinned_list.insert(pin);
    }
    vector<string> pinned_set;
    vector<string> unpinned_set;
    for (string program : name_of_used_program)
    {
        if (pinned_list.count(program))
            pinned_set.push_back(program);
        else
            unpinned_set.push_back(program);
    }
    for (string program : pinned_set)
        cout << program << '\n';
    for (string program : unpinned_set)
        cout << program << '\n';
}