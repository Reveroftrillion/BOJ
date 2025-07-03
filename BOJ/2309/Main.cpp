#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[9], sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + 9);

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if ((sum - arr[i] - arr[j]) == 100)
            {
                sum = 0;
                arr[i] = 0;
                arr[j] = 0;
                break;
            }
        }
        if (sum == 0)
            break;
    }
    for (int i = 0; i < 9; i++)
        if (arr[i] > 0)
            cout << arr[i] << "\n";
}