#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fruit, snake;
    cin >> fruit >> snake;
    vector<int> height;
    for (int i = 0; i < fruit; i++)
    {
        int k;
        cin >> k;
        height.push_back(k);
    }
    sort(height.begin(), height.end());
    for (int j = 0; j < height.size(); j++)
    {
        if (height[j] <= snake)
        {
            snake++;
        }
    }
    cout << snake << endl;
}