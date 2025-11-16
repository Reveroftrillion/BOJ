#include <bits/stdc++.h>
using namespace std;

struct Planet
{
    int x, y, z, idx;
};

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

struct DSU
{
    vector<int> parent;
    vector<int> tree_size;

    DSU(int n) : parent(n), tree_size(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        int root_A = find(a);
        int root_B = find(b);
        if (root_A == root_B)
            return false;
        if (tree_size[root_A] < tree_size[root_B])
        {
            swap(root_A, root_B);
        }
        parent[root_B] = root_A;
        tree_size[root_A] += tree_size[root_B];

        return true;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<Planet> planets;
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        planets.push_back({x, y, z, i});
    }

    vector<Edge> edges;

    {
        vector<pair<int, int>> v;
        for (auto &p : planets)
        {
            v.push_back({p.x, p.idx});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < N - 1; i++)
        {
            int u = v[i].second;
            int vv = v[i + 1].second;
            int w = abs(v[i + 1].first - v[i].first);
            edges.push_back({u, vv, w});
        }
    }

    {
        vector<pair<int, int>> v;
        for (auto &p : planets)
        {
            v.push_back({p.y, p.idx});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < N - 1; i++)
        {
            int u = v[i].second;
            int vv = v[i + 1].second;
            int w = abs(v[i + 1].first - v[i].first);
            edges.push_back({u, vv, w});
        }
    }

    {
        vector<pair<int, int>> v;
        for (auto &p : planets)
        {
            v.push_back({p.z, p.idx});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < N - 1; i++)
        {
            int u = v[i].second;
            int vv = v[i + 1].second;
            int w = abs(v[i + 1].first - v[i].first);
            edges.push_back({u, vv, w});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(N);

    long long ans = 0;
    int cnt = 0;

    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            ans += e.w;
            cnt++;
            if (cnt == N - 1)
                break;
        }
    }

    cout << ans << endl;
}