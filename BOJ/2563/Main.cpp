#include <iostream>
using namespace std;

bool paper[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int p, q;
        cin >> p >> q;
        for (int j = p; j < p + 10; j++)
        {
            for (int k = q; k < q + 10; k++)
            {
                paper[j][k] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (paper[i][j] == true)
                answer++;
        }
    }
    cout << answer << '\n';
}