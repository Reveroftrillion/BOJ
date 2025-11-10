#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;
    vector<vector<int>> tree(N + 1);

    for (int i = 1; i < N; i++)
    {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    } // 받아온 간선 정리하기.

    vector<int> parent(N + 1, 0);
    vector<int> order;

    stack<int> DFS;
    DFS.push(R);
    parent[R] = -1;

    while (!DFS.empty())
    {
        int current_num = DFS.top();
        DFS.pop();
        order.push_back(current_num);
        for (int next_num : tree[current_num])
        {
            if (parent[next_num] == 0)
            {
                parent[next_num] = current_num;
                DFS.push(next_num);
            }
        }
    }

    int os = order.size();

    vector<int> subtree(N + 1, 1);
    for (int i = os - 1; i >= 0; i--)
    {
        int node = order[i];
        for (int next : tree[node])
        {
            if (next == parent[node])
                continue;
            subtree[node] += subtree[next];
        }
    }

    for (int j = 0; j < Q; j++)
    {
        int k;
        cin >> k;
        cout << subtree[k] << '\n';
    }
}