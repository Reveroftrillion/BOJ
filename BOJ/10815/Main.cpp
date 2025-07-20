#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> sang;

int search(int start, int end, long long num)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (sang[mid] == num)
        {
            return 1;
        }
        else if (sang[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return 0;
}

int main()
{
    int N, M;
    long long element;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> element;
        sang.push_back(element);
    }

    sort(sang.begin(), sang.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> element;
        cout << search(0, N - 1, element) << " ";
    }

    return 0;
}