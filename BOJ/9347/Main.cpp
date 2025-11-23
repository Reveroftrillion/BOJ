#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void solve()
{
    int R, C;
    if (!(cin >> R >> C))
        return;

    // 맵 주위에 0으로 둘러싸서 외부 진입 처리 더 쉽게 만듦
    // (1, 1)부터 (R, C)까지가 맵
    vector<vector<int>> grid(R + 2, vector<int>(C + 2, 0));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> grid[i][j];
        }
    }

    int H = R + 2;
    int W = C + 2;

    vector<vector<int>> dist(H, vector<int>(W, INF));
    deque<pair<int, int>> dq;

    // dp 쓰기
    dist[0][0] = 0;
    dq.push_back({0, 0});

    while (!dq.empty())
    {
        auto [r, c] = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;

            int weight = (grid[nr][nc] == 1) ? 1 : 0;

            if (dist[nr][nc] > dist[r][c] + weight)
            {
                dist[nr][nc] = dist[r][c] + weight;
                if (weight == 0)
                {
                    dq.push_front({nr, nc});
                }
                else
                {
                    dq.push_back({nr, nc});
                }
            }
        }
    }

    // 꽃으로 이뤄진 연결된 영역들 찾아서 집계
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int max_broken_fences = -1;
    long long max_flowers_count = 0;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (grid[i][j] == 0 && !visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                long long current_cluster_size = 0;
                int current_cluster_cost = dist[i][j];

                while (!q.empty())
                {
                    auto [cur_r, cur_c] = q.front();
                    q.pop();
                    current_cluster_size++;

                    current_cluster_cost = min(current_cluster_cost, dist[cur_r][cur_c]);

                    for (int k = 0; k < 4; k++)
                    {
                        int nr = cur_r + dr[k];
                        int nc = cur_c + dc[k];

                        if (nr >= 1 && nr <= R && nc >= 1 && nc <= C)
                        {
                            if (grid[nr][nc] == 0 && !visited[nr][nc])
                            {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                // 여기가 특이한 지점
                // 가장 뚫기 힘든 지점들을 다 구하고 그걸 더해줘야 함
                if (current_cluster_cost > max_broken_fences)
                {
                    max_broken_fences = current_cluster_cost;
                    max_flowers_count = current_cluster_size;
                }
                else if (current_cluster_cost == max_broken_fences)
                {
                    max_flowers_count += current_cluster_size;
                }
            }
        }
    }

    cout << max_broken_fences << " " << max_flowers_count << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}