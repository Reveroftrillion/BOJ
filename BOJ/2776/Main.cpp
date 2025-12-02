#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int p = 0; p < T; p++)
    {
        int N;
        cin >> N;
        vector<int> note1;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            note1.push_back(k);
        }
        sort(note1.begin(), note1.end());

        int M;
        cin >> M;
        vector<int> note2;
        for (int i = 0; i < M; i++)
        {
            int k_;
            cin >> k_;
            bool found = binary_search(note1.begin(), note1.end(), k_);
            cout << (found ? "1\n" : "0\n");
        }
    }
}
