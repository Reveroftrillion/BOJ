#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS
    dfs(V);
    cout << "\n";

    fill(visited.begin(), visited.end(), false);
    bfs(V);
    cout << "\n";

    return 0;
}