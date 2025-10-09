#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int answer1 = 0;
int answer2 = 0;

int partition(vector<long long> &arr, int p, int r, int K)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[++i], arr[j]);
            cnt++;
            if (cnt == K)
            {
                answer1 = min(arr[i], arr[j]);
                answer2 = max(arr[i], arr[j]);
            }
        }
    }
    if (i + 1 != r)
    {
        swap(arr[i + 1], arr[r]);
        cnt++;
        if (cnt == K)
        {
            answer1 = min(arr[i + 1], arr[r]);
            answer2 = max(arr[i + 1], arr[r]);
        }
    }
    return (i + 1);
}

void quick_sort(vector<long long> &arr, int p, int r, int K)
{
    if (p < r)
    {
        int q = partition(arr, p, r, K);
        quick_sort(arr, p, q - 1, K);
        quick_sort(arr, q + 1, r, K);
    }
}

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> qs;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        qs.push_back(a);
    }
    quick_sort(qs, 0, qs.size() - 1, K);
    if (cnt < K)
    {
        cout << -1;
    }
    else
    {
        cout << answer1 << " " << answer2;
    }
}