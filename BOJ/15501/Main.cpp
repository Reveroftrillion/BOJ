#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const vector<int> &p)
{
    int m = (int)p.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

// KMP: returns true if pattern p appears in text t
bool kmp_find(const vector<int> &t, const vector<int> &p)
{
    if (p.empty())
        return true;
    vector<int> pi = prefix_function(p);
    int n = (int)t.size(), m = (int)p.size();
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
            ++j;
        if (j == m)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    if (n == 1)
    {
        cout << (A[0] == B[0] ? "good puzzle" : "bad puzzle") << '\n';
        return 0;
    }

    // 텍스트: A + A (길이 2n)
    vector<int> AA;
    AA.reserve(2 * n);
    AA.insert(AA.end(), A.begin(), A.end());
    AA.insert(AA.end(), A.begin(), A.end());

    bool ok = false;
    if (kmp_find(AA, B))
        ok = true;

    if (!ok)
    {
        vector<int> revA = A;
        reverse(revA.begin(), revA.end());
        vector<int> revrevA;
        revrevA.reserve(2 * n);
        revrevA.insert(revrevA.end(), revA.begin(), revA.end());
        revrevA.insert(revrevA.end(), revA.begin(), revA.end());
        if (kmp_find(revrevA, B))
            ok = true;
    }

    cout << (ok ? "good puzzle" : "bad puzzle") << '\n';
    return 0;
}
