#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> height(t); // 벡터의 크기만 지정해준다.
    vector<int> weight(t);
    vector<int> cnt(t, 1);
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        weight[i] = x; // 크기가 정해진 벡터에 push_back 하면 크기는 정해진 거 뒤에 붙어서 더 커진다.
        height[i] = y;
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (i == j)
                continue;
            else if (weight[j] > weight[i] && height[j] > height[i]) // 들어온 사람이 덩치가 더 크면 i의 등수가 하나씩 밀려남.
            {
                cnt[i]++;
            }
        }
    }

    for (int k = 0; k < t; k++)
    {
        cout << cnt[k] << " ";
    }
}