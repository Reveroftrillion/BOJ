#include <bits/stdc++.h>
using namespace std;

const long long NEGATIVE_INFINITY = LLONG_MIN / 100000;

struct Edge
{
    int s_c, e_c;
    long long price;
};

int main()
{
    int N, start_city, end_city, M;
    cin >> N >> start_city >> end_city >> M;

    vector<Edge> edges;

    vector<vector<int>> adj(N);         // 인접 리스트
    vector<vector<int>> reverse_adj(N); // 인접 리스트 역방향

    for (int i = 0; i < M; i++)
    {
        int s_c, e_c;
        long long price;
        cin >> s_c >> e_c >> price;
        edges.push_back({s_c, e_c, price});
        adj[s_c].push_back(e_c);
        reverse_adj[e_c].push_back(s_c); // 연결된 도시들 정방향, 역방향 모두 저장
    }

    vector<long long> max_money(N);
    for (int j = 0; j < N; j++)
    {
        cin >> max_money[j];
    }

    vector<char> reachable_from_start(N, 0);

    queue<int> q;
    q.push(start_city);
    reachable_from_start[start_city] = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int nx : adj[x])
        {
            if (!reachable_from_start[nx])
            {
                reachable_from_start[nx] = 1;
                q.push(nx);
            }
        }
    }

    if (!reachable_from_start[end_city])
    {
        cout << "gg" << endl;
        return 0;
    }

    // 여기부터 벨만 포드 구현
    vector<long long> dist(N, NEGATIVE_INFINITY);
    dist[start_city] = max_money[start_city];

    for (int i = 0; i < N - 1; i++)
    {
        bool updated = false;
        for (auto &e : edges)
        {
            if (dist[e.s_c] == NEGATIVE_INFINITY)
            {
                continue;
            }
            long long gained_money = max_money[e.e_c] - e.price;

            if (dist[e.e_c] < dist[e.s_c] + gained_money)
            {
                dist[e.e_c] = dist[e.s_c] + gained_money;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    // 여기는 음의 사이클 있는지 확인하기
    // dist가 무한히 증가하는 사이클
    vector<char> cycle(N, 0);
    for (auto &e : edges)
    {
        if (dist[e.s_c] == NEGATIVE_INFINITY)
        {
            continue;
        }
        long long gain = max_money[e.e_c] - e.price;

        if (dist[e.e_c] < dist[e.s_c] + gain)
        {
            cycle[e.e_c] = 1;
        }
    }

    vector<char> affected(N, 0);
    queue<int> q1;
    for (int i = 0; i < N; i++)
    {
        if (cycle[i])
        {
            affected[i] = 1;
            q1.push(i);
        }
    }

    while (!q1.empty())
    {
        int x = q1.front();
        q1.pop();
        for (int nx : adj[x])
        {
            if (!affected[nx])
            {
                affected[nx] = 1;
                q1.push(nx);
            }
        }
    }

    // end_city까지 도달할 수 있는지 reverse_adj 검사
    vector<char> reachable_to_end(N, 0);

    queue<int> q_;
    q_.push(end_city);
    reachable_to_end[end_city] = 1;
    while (!q_.empty())
    {
        int x = q_.front();
        q_.pop();
        for (int prev : reverse_adj[x])
        {
            if (!reachable_to_end[prev])
            {
                reachable_to_end[prev] = 1;
                q_.push(prev);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (affected[i] && reachable_from_start[i] && reachable_to_end[i])
        {
            cout << "Gee" << endl;
            return 0;
        }
    }

    cout << dist[end_city] << endl;
    return 0;
}