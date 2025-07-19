#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    for (int next : graph[node])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    cout << components << '\n';
}