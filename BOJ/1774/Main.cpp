#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric> //iota 쓸 때 사용
#include <iomanip>
using namespace std;

struct Edge
{
    int u, v;
    double distance;
};

struct DSU // Disjoint Set Union
{
    vector<int> parent;
    vector<int> rank;

    DSU(int n = 0) // 생성자
    {
        parent.resize(n);
        rank.assign(n, 0);                     // rank 벡터는 전부 0으로 채우기
        iota(parent.begin(), parent.end(), 0); // parent를 [0, 1, 2 ... n]으로 초기화
    }

    int find(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }
        return parent[n] = find(parent[n]); // 경로 압축시키기 (루트 찾고 갱신시켜주기)
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> location(N);
    vector<pair<int, int>> connect(M);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        location[i] = {x, y};
    }

    for (int j = 0; j < M; j++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        connect[j] = {num1 - 1, num2 - 1};
    }

    DSU dsu(N);
    for (auto &pair : connect)
    {
        dsu.unite(pair.first, pair.second);
    }

    vector<Edge> edge;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double dist_x = location[i].first - location[j].first;
            double dist_y = location[i].second - location[j].second;
            double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
            edge.push_back({i, j, dist});
        }
    }

    sort(edge.begin(), edge.end(), [](const Edge &front, const Edge &back)
         { return front.distance < back.distance; });

    double answer = 0.0;
    for (auto &k : edge)
    {
        if (dsu.unite(k.u, k.v))
        {
            answer += k.distance;
        }
    }

    cout << fixed << setprecision(2) << answer << '\n';
    return 0;
}