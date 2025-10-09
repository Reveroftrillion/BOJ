#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;
long long answer = 0;

void merge(vector<long long> &arr, int p, int q, int r, int K)
{
    int i = p;
    int j = q + 1;
    int t = 0;
    vector<long long> tmp(r - p + 1);
    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[t++] = arr[i++];
        }
        else
        {
            tmp[t++] = arr[j++];
        }
    }
    while (i <= q)
    {
        tmp[t++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[t++] = arr[j++];
    }
    i = p;
    t = 0;
    while (i <= r)
    {
        arr[i++] = tmp[t++];
        cnt++;
        if (cnt == K)
        {
            answer = arr[i - 1];
        }
    }
}

void merge_sort(vector<long long> &arr, int p, int r, int K)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(arr, p, q, K);
        merge_sort(arr, q + 1, r, K);
        merge(arr, p, q, r, K);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> ms;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        ms.push_back(a);
    }
    merge_sort(ms, 0, ms.size() - 1, K);
    if (answer == 0)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}