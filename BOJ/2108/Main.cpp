#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> check(8001, 0); // -4000부터 4000까지 저장용
    long long sum = 0;
    int minimum = 4000;
    int maximum = -4000;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        sum += k;
        check[k + 4000]++;
        minimum = min(k, minimum);
        maximum = max(k, maximum);
    }

    double average = (double)sum / t;
    int real_av = round(average);
    cout << real_av << '\n';

    int cnt = 0;
    int middle = (t + 1) / 2;
    int mid_num;
    for (int i = 0; i <= 8000; i++)
    {
        cnt += check[i];
        if (cnt >= middle)
        {
            mid_num = i - 4000;
            break;
        }
    }
    cout << mid_num << '\n';

    vector<int> choibin;
    int max_frequency = *max_element(check.begin(), check.end());
    for (int i = 0; i <= 8000; i++)
    {
        if (check[i] == max_frequency)
        {
            choibin.push_back(i - 4000);
        }
    }
    if (choibin.size() > 1)
    {
        cout << choibin[1] << '\n';
    }
    else
    {
        cout << choibin[0] << '\n';
    }

    cout << maximum - minimum << '\n';
}