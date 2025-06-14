#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int money = 0;
    vector<int> arr(t + 2, 0); // 마지막에서 뒤에 2개 비교하는거 고려.

    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < t; i++)
    {
        if (arr[i] == 0)
            continue;
        int duo = min(arr[i], arr[i + 1] - arr[i + 2]);

        // 2) trio: i, i+1, i+2에서 묶음 구매
        int trio = min(arr[i], min(arr[i + 1], arr[i + 2]));
        if (trio > 0)
        {
            arr[i] -= trio;
            arr[i + 1] -= trio;
            arr[i + 2] -= trio;
            money += 7 * trio;
        }

        // 3) 일반 duo: i, i+1에서 묶음 구매
        duo = min(arr[i], arr[i + 1]);
        if (duo > 0)
        {
            arr[i] -= duo;
            arr[i + 1] -= duo;
            money += 5 * duo;
        }

        // 4) single: 남은 i번 공장 라면 개별 구매
        if (arr[i] > 0)
        {
            money += 3 * arr[i];
            arr[i] = 0;
        }
    }

    cout << money << "\n";
    return 0;
}
