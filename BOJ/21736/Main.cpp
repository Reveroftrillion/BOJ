#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> campus;
bool visited[600][600];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    campus.resize(N);

    int sx = -1, sy = -1;

    for (int i = 0; i < N; i++) {
        cin >> campus[i];
        for (int j = 0; j < M; j++) {
            if (campus[i][j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int cnt = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visited[nx][ny] || campus[nx][ny] == 'X')
                continue;

            visited[nx][ny] = true;
            if (campus[nx][ny] == 'P')
                cnt++;

            q.push({nx, ny});
        }
    }

    if (cnt == 0)
        cout << "TT\n";
    else
        cout << cnt << "\n";

    return 0;
}
