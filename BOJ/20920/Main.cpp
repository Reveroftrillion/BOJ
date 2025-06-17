#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, length;
    cin >> a >> length;
    map<string, int> dictionary;
    for (int i = 0; i < a; i++)
    {
        string str;
        cin >> str;
        if (str.size() >= length)
        {
            dictionary[str]++;
        }
    }

    vector<pair<string, int>> wordfilter; // 벡터를 쓰되 단어, 숫자 조합으로 쓰려고
    for (auto &entry : dictionary)
    { // 저장해둔 맵 안에 있는 쌍들 검사
        wordfilter.push_back(entry);
    }

    // 람다 함수를 통해 정렬 방법 정의
    sort(wordfilter.begin(), wordfilter.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         {
        if(a.second != b.second){
            return a.second > b.second;
        }
        else if(a.first.size() != b.first.size()){
            return a.first.size() > b.first.size();
        }
        return a.first < b.first; });

    for (const auto &entry : wordfilter)
    {
        cout << entry.first << '\n';
    }
}