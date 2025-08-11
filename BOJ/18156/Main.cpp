#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    int half_n = n / 2;

    for (int i = 0; i < n; ++i)
    {
        int black_count = 0;
        for (char c : grid[i])
        {
            if (c == 'B')
            {
                black_count++;
            }
        }
        if (black_count != half_n)
        {
            cout << 0 << "\n";
            return 0;
        }

        for (int j = 0; j < n - 2; ++j)
        {
            if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2])
            {
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    for (int j = 0; j < n; ++j)
    {
        int black_count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][j] == 'B')
            {
                black_count++;
            }
        }
        if (black_count != half_n)
        {
            cout << 0 << "\n";
            return 0;
        }

        for (int i = 0; i < n - 2; ++i)
        {
            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j])
            {
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    cout << 1 << "\n";

    return 0;
}