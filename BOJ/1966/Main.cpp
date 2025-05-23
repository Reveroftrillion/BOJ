#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        deque<int> printer;
        deque<int> original; // 원래 위치 저장해두기.

        for (int j = 0; j < a; j++)
        {
            int k;
            cin >> k;
            printer.push_back(k);
            original.push_back(j);
        }

        int cnt = 0;

        while (!printer.empty())
        {
            int max = *max_element(printer.begin(), printer.end()); // 이거 쓰려면 algorithm include 해주기
            if (printer.front() == max)
            {
                cnt++;
                if (original.front() == b)
                {
                    cout << cnt << '\n';
                    break;
                }
                printer.pop_front();
                original.pop_front();
            }
            else
            {
                printer.push_back(printer.front());
                original.push_back(original.front());
                printer.pop_front();
                original.pop_front();
            }
        }
    }
}