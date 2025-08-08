#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> dist;

int bfs(int start, int target)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == target)
            return dist[cur];

        for (int next : graph[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    int N, A, B, M;
    cin >> N >> A >> B >> M;

    graph.resize(N + 1);
    dist.resize(N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    cout << bfs(A, B) << "\n";

    return 0;
}