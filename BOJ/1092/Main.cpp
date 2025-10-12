#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> crain;
    vector<int> box;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        crain.push_back(a);
    }
    int M;
    cin >> M;
    for (int j = 0; j < M; j++)
    {
        int b;
        cin >> b;
        box.push_back(b);
    }

    sort(crain.begin(), crain.end());
    reverse(crain.begin(), crain.end());
    sort(box.begin(), box.end());
    reverse(box.begin(), box.end());

    if (box[0] > crain[0])
    {
        cout << -1 << endl;
        return 0;
    }

    vector<char> used(M, 0);
    int moved = 0;
    int minutes = 0;

    while (moved < M)
    {
        int j = 0;
        for (int i = 0; i < N; ++i)
        {
            while (j < M)
            {
                if (!used[j] && crain[i] >= box[j])
                {
                    used[j] = 1;
                    moved++;
                    j++;
                    break;
                }
                j++;
            }
            if (moved == M)
                break;
        }
        minutes++;
    }

    cout << minutes << endl;
    return 0;
}