#include <iostream>
#include <vector>
using namespace std;

long long swap_cnt = 0;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp; // 여기다가 저장하고 bubble에 다시 넘겨주기.

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            swap_cnt += (mid - i + 1); // 역순으로 있는 거 다 세서 넘기기
            j++;
        }
    }

    while (i <= mid) // 왼쪽만 남았을 때 temp에 다 밀어넣기
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) // 오른쪽만 남았을 때 temp에 다 밀어넣기
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) // 전체를 temp에 다 씌우기
    {
        arr[left + k] = temp[k];
    }
}

void merge_sort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> bubble(N);
    for (int i = 0; i < N; i++)
        cin >> bubble[i];
    merge_sort(bubble, 0, N - 1);

    cout << swap_cnt << '\n';
    return 0;
}