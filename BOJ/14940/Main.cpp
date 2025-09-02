#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> dist;
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            if (dist[nx][ny] != -1)
            {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    map.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, -1));

    int startX, startY;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                startX = i;
                startY = j;
            }
            if (map[i][j] == 0)
            {
                dist[i][j] = 0;
            }
        }
    }

    q.push({startX, startY});
    dist[startX][startY] = 0;

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}