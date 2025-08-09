#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    struct Node
    {
        int wordIndex = -1;
        array<int, 26> next;
        Node() { next.fill(-1); }
    };
    vector<Node> nodes;
    Trie() { nodes.push_back(Node()); }

    void insert(const string &word, int idx)
    {
        int cur = 0;
        for (char c : word)
        {
            int d = c - 'A';
            if (nodes[cur].next[d] == -1)
            {
                nodes[cur].next[d] = nodes.size();
                nodes.push_back(Node());
            }
            cur = nodes[cur].next[d];
        }
        nodes[cur].wordIndex = idx;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> Q(N), A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Q[i] >> A[i];
    }

    Trie trie;
    for (int i = 0; i < N; i++)
    {
        trie.insert(Q[i], i);
    }

    while (M--)
    {
        string S;
        cin >> S;
        string ans = "";

        for (int start = 0; start < (int)S.size(); start++)
        {
            vector<int> found_indices;
            int cur = 0;

            for (int step = 0; start + step < (int)S.size(); step++)
            {
                int d = S[start + step] - 'A';
                if (trie.nodes[cur].next[d] == -1)
                {
                    break;
                }
                cur = trie.nodes[cur].next[d];
                if (trie.nodes[cur].wordIndex != -1)
                {
                    found_indices.push_back(trie.nodes[cur].wordIndex);
                }
            }

            if (!found_indices.empty())
            {
                sort(found_indices.begin(), found_indices.end(), [&](int i, int j)
                     { return Q[i] < Q[j]; });

                for (int idx : found_indices)
                {
                    ans += A[idx];
                }
            }
        }

        if (ans.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}
