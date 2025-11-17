#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int cx, int cy, const vector<vector<char>> &paper, vector<vector<int>> &visited)
{
    int n = paper.size();
    int m = paper[0].size();
    char target = paper[cx][cy];
    queue<pair<int, int>> q;
    visited[cx][cy] = 1;
    q.push({cx, cy});
    int cnt = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny])
                continue;
            if (paper[nx][ny] != '1')
                continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> paper(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            paper[i][j] = c;
        }
    }

    int picture = 0;
    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && paper[i][j] == '1')
            {
                picture++;
                int area = bfs(i, j, paper, visited);
                max_area = max(area, max_area);
            }
        }
    }

    cout << picture << endl;
    cout << max_area << endl;
}