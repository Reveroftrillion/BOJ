#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

int dp(vector<int> &sonnim, vector<int> &prefix, int k)
{
    int n = sonnim.size();
    vector<vector<int>> dp(4, vector<int>(n + 1, 0));

    for (int i = 1; i <= 3; i++)
    {
        for (int j = k; j <= n; j++)
        {
            int how_many = prefix[j] - prefix[j - k];
            // "이전에 i-1대 기관차가 끌었던 최대 손님 수" + "이번 기관차가 끄는 k칸 손님 수"
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + how_many);
        }
    }
    return dp[3][n];
}

int main()
{
    int train;
    cin >> train;
    vector<int> customer(train);
    for (int i = 0; i < train; i++)
    {
        cin >> customer[i];
    }
    vector<int> prefix(train + 1, 0);
    for (int i = 1; i <= train; i++)
    {
        prefix[i] = prefix[i - 1] + customer[i - 1];
    }
    int max_num;
    cin >> max_num;
    cout << dp(customer, prefix, max_num) << endl;
}