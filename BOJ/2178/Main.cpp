#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int cx, int cy, const vector<vector<char>> &maze, vector<vector<int>> &distance)
{
    int n = maze.size();
    int m = maze[0].size();
    char target = maze[cx][cy];
    queue<pair<int, int>> q;
    distance[cx][cy] = 1;
    q.push({cx, cy});
    int cnt = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1)
            return distance[x][y];

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (distance[nx][ny])
                continue;
            if (maze[nx][ny] != '1')
                continue;
            distance[nx][ny] = distance[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return distance[n - 1][m - 1];
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> maze(N, vector<char>(M));
    vector<vector<int>> distance(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        int a = 0;
        for (char c : str)
        {
            maze[i][a] = c;
            a++;
        }
    }

    int ans = bfs(0, 0, maze, distance);
    cout << ans << '\n';
}