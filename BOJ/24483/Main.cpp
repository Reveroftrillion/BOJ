#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int N, M, R;
vector<int> graph[MAX];
bool visited[MAX];
long long depth[MAX];
long long visited_order[MAX];
int order_cnt = 1;

void dfs(int u, int d)
{
    visited[u] = true;
    depth[u] = d;
    visited_order[u] = order_cnt++;

    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v, d + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= N; ++i)
    {
        depth[i] = -1;
    }

    dfs(R, 0);

    long long total_sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        total_sum += depth[i] * visited_order[i];
    }

    cout << total_sum << endl;

    return 0;
}