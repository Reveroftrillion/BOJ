#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> maze;
int sx, sy;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int init_dir;

long long simulate(bool left) {
    int x = sx, y = sy, dir = init_dir;
    long long cnt = 0;

    while (maze[x][y] != 'E') {
        if (left) dir = (dir + 3) % 4;
        else      dir = (dir + 1) % 4;

        while (true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '*')
                break;

            if (left) dir = (dir + 1) % 4;
            else      dir = (dir + 3) % 4;
        }

        x += dx[dir];
        y += dy[dir];
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    maze.resize(N);
    for (int i = 0; i < N; i++) cin >> maze[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (maze[i][j] == 'S') {
                sx = i; sy = j;
            }

    // 초기 방향 (범위 체크 필수)
    for (int d = 0; d < 4; d++) {
        int nx = sx + dx[d];
        int ny = sy + dy[d];
        if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '*') {
            init_dir = d;
            break;
        }
    }

    long long L = simulate(true);
    long long R = simulate(false);

    if (L < R) cout << "LEFT IS BEST\n";
    else if (R < L) cout << "RIGHT IS BEST\n";
    else cout << "SAME\n";
}
