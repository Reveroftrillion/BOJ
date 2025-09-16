#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M))
        return 0;
    vector<string> S(3 * N);
    for (int i = 0; i < 3 * N; ++i)
        cin >> S[i];

    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    vector<vector<array<bool, 4>>> edge(N, vector<array<bool, 4>>(M, {false, false, false, false}));
    auto inb = [&](int r, int c)
    { return 0 <= r && r < N && 0 <= c && c < M; };

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int br = 3 * i, bc = 3 * j;
            bool allDot = true;
            for (int r = 0; r < 3; ++r)
                for (int c = 0; c < 3; ++c)
                    if (S[br + r][bc + c] == '#')
                        allDot = false;

            if ((i + j) % 2 == 0)
            {
                edge[i][j][0] = (S[br + 0][bc + 1] == '#');
                edge[i][j][1] = (S[br + 1][bc + 2] == '#');
                edge[i][j][2] = (S[br + 2][bc + 1] == '#');
                edge[i][j][3] = (S[br + 1][bc + 0] == '#');
            }
        }
    }

    for (int it = 0; it < 3; ++it)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                for (int d = 0; d < 4; ++d)
                {
                    if (!edge[i][j][d])
                        continue;
                    int ni = i + dr[d], nj = j + dc[d];
                    if (!inb(ni, nj))
                        continue;
                    int od = (d + 2) % 4;
                    edge[ni][nj][od] = true;
                }
            }
        }
    }

    vector<string> out(3 * N, string(3 * M, '.'));
    auto draw_cell = [&](int i, int j)
    {
        int br = 3 * i, bc = 3 * j;
        out[br + 1][bc + 1] = '#';
        if (edge[i][j][0])
            out[br + 0][bc + 1] = '#';
        if (edge[i][j][1])
            out[br + 1][bc + 2] = '#';
        if (edge[i][j][2])
            out[br + 2][bc + 1] = '#';
        if (edge[i][j][3])
            out[br + 1][bc + 0] = '#';
    };

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            draw_cell(i, j);

    for (int i = 0; i < 3 * N; ++i)
        cout << out[i] << '\n';
    return 0;
}
