#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;

long long partition(vector<long long> &arr, int p, int r, int K)
{
    long long x = arr[r];
    long long i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[++i], arr[j]);
            cnt++;
            if (cnt == K)
            {
                for (int f = 0; f < arr.size(); f++)
                {
                    cout << arr[f] << " ";
                }
                exit(0);
            }
        }
    }
    if (i + 1 != r)
    {
        swap(arr[i + 1], arr[r]);
        cnt++;
        if (cnt == K)
        {
            for (int f = 0; f < arr.size(); f++)
            {
                cout << arr[f] << " ";
            }
            exit(0);
        }
    }
    return i + 1;
}

long long select(vector<long long> &arr, int p, int r, int q, int K)
{
    if (p == r)
    {
        return arr[p];
    }
    long long t;
    t = partition(arr, p, r, K);
    long long k = t - p + 1;
    if (q < k)
    {
        return select(arr, p, t - 1, q, K);
    }
    else if (q == k)
    {
        return arr[t];
    }
    else
    {
        return select(arr, t + 1, r, q - k, K);
    }
}

int main()
{
    long long N, Q, K;
    cin >> N >> Q >> K;
    vector<long long> sq;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        sq.push_back(a);
    }
    select(sq, 0, sq.size() - 1, Q, K);
    cout << "-1" << endl;
}