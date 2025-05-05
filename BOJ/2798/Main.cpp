#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, goal;
    cin >> t >> goal;
    vector<int> player;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        player.push_back(k);
    }
    // 카드 조합 3개를 찾기 위해서 브루트포스 (완전 탐색) 사용
    // 시간은 오래 걸리지만 100개 이하면 대부분 가능
    int max = 0;
    for (int i = 0; i < t - 2; i++)
    {
        for (int j = i + 1; j < t - 1; j++)
        {
            for (int k = j + 1; k < t; k++)
            {
                int sum = player[i] + player[j] + player[k];
                if (sum <= goal && max < sum)
                {
                    max = sum;
                }
            }
        }
    }
    cout << max << endl;
}