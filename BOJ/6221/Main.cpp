#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bale
{
    int width;
    int breadth;
};

int main()
{
    int n;
    cin >> n;
    vector<Bale> bales(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> bales[i].width >> bales[i].breadth;
    }

    sort(bales.begin(), bales.end(), [](const Bale &a, const Bale &b)
         {
        if (a.width != b.width)
            return a.width > b.width;
        return a.breadth > b.breadth; });

    vector<int> dp(n, 1);
    int answer = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (bales[j].width > bales[i].width &&
                bales[j].breadth > bales[i].breadth)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}
