#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<long long> &arr, int N, int K)
{
    int num = 0;
    int last = N - 1;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < last; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                num++;
            }
            if (num == K)
            {
                for (int i = 0; i < N; i++)
                {
                    cout << arr[i] << " ";
                }
                return;
            }
        }
        last--;
    }
    if (num < K)
    {
        cout << "-1" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> algo;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        algo.push_back(a);
    }
    bubble_sort(algo, N, K);
}