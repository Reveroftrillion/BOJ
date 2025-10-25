#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C))
        return;

    vector<vector<int>> jungle(R + 1, vector<int>(C + 1));
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> jungle[i][j];
        }
    }

    vector<vector<bool>> visited(R + 1, vector<bool>(C + 1, false));

    int current_r = 1;
    int current_c = 1;
    long long total_papaya = 0;

    total_papaya += jungle[current_r][current_c];
    visited[current_r][current_c] = true;

    while (current_r != R || current_c != C)
    {
        int max_papaya = -1;
        int next_r = -1;
        int next_c = -1;

        for (int i = 0; i < 4; ++i)
        {
            int nr = current_r + dr[i];
            int nc = current_c + dc[i];

            if (nr >= 1 && nr <= R && nc >= 1 && nc <= C)
            {
                if (!visited[nr][nc])
                {
                    if (jungle[nr][nc] > max_papaya)
                    {
                        max_papaya = jungle[nr][nc];
                        next_r = nr;
                        next_c = nc;
                    }
                }
            }
        }

        if (next_r == -1 || next_c == -1)
        {
            break;
        }

        current_r = next_r;
        current_c = next_c;
        total_papaya += jungle[current_r][current_c];
        visited[current_r][current_c] = true;
    }

    cout << total_papaya << "\n";
}

int main()
{
    solve();
    return 0;
}