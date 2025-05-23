#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// vector 쓰니까 find 쓰면 처음부터 끝까지를 보는 거라 시간초과가 뜸 : O(N^2)라서
// unordered set 쓰니까 find할 때 O(1) 밖에 안 걸림
// unordered set은 해시테이블 써서 그럼

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    unordered_set<int> selected;
    int sticker = 0;
    int max_stick = 0;
    for (int i = 0; i < 2 * t; i++)
    {
        int k;
        cin >> k;
        if (selected.find(k) == selected.end())
        {
            selected.insert(k);
            sticker++;
            max_stick = max(sticker, max_stick);
        }
        else
        {
            selected.erase(k);
            sticker--;
        }
    }
    cout << max_stick << endl;
    return 0;
}