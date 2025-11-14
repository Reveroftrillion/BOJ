#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> comp_id(N, vector<int>(M, -1));
    vector<int> comp_size;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    int id = 0;
    int row[4] = {-1, 1, 0, 0};
    int column[4] = {0, 0, -1, 1};

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (grid[r][c] == 0 && comp_id[r][c] == -1)
            {
                queue<pair<int, int>> q;
                q.push({r, c});
                comp_id[r][c] = id;
                int cnt = 0;
                while (!q.empty())
                {
                    auto current = q.front();
                    q.pop();
                    int cur_r = current.first;
                    int cur_c = current.second;
                    cnt++;

                    for (int i = 0; i < 4; i++)
                    {
                        int new_r = cur_r + row[i];
                        int new_c = cur_c + column[i];
                        if (new_r < 0 || new_c < 0 || new_r >= N || new_c >= M)
                            continue;
                        if (grid[new_r][new_c] == 0 && comp_id[new_r][new_c] == -1)
                        {
                            comp_id[new_r][new_c] = id;
                            q.push({new_r, new_c});
                        }
                    }
                }
                comp_size.push_back(cnt);
                id++;
            }
        }
    }

    vector<int> visited(id, -1);
    int timestamp = 0;

    for (int r = 0; r < N; r++)
    {
        string line;
        for (int c = 0; c < M; c++)
        {
            if (grid[r][c] == 0)
            {
                line.push_back('0');
            }
            else
            {
                timestamp++;
                int sum = 1;
                for (int k = 0; k < 4; k++)
                {
                    int nr = r + row[k];
                    int nc = c + column[k];
                    if (nr < 0 || nc < 0 || nr >= N || nc >= M)
                        continue;
                    int nid = comp_id[nr][nc];
                    if (nid == -1)
                        continue;
                    if (visited[nid] == timestamp)
                        continue;
                    visited[nid] = timestamp;
                    sum += comp_size[nid];
                }

                int num = sum % 10;
                line.push_back(char('0' + num));
            }
        }
        cout << line << endl;
    }
}