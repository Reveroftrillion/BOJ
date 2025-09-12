#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[15001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int start = 0;
    int end = n - 1;
    int cnt = 0;
    while (end - start > 0)
    {
        int sum = arr[start] + arr[end];
        if (sum == m)
        {
            cnt++;
            end--;
        }
        else if (sum > m)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    cout << cnt << endl;
}