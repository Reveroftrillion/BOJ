#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < 14; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int junhyeon = 0, sungmin = 0;
    int n_is = N;
    for (auto it : v)
    {
        if (it <= n_is)
        {
            junhyeon = n_is / it;
            n_is = n_is % it;
            break;
        }
    }
    junhyeon = n_is + (junhyeon * v[13]);

    int cnt = 0;
    int buy_idx = 1e9;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
            cnt++;
        else
            cnt = 0;
        if (cnt >= 3)
        {
            if (v[i] <= N)
            {
                sungmin += N / v[i];
                N = N % v[i];
                buy_idx = i;
            }
        }
    }
    cnt = 0;
    bool flag = false;
    for (int i = buy_idx + 1; i < v.size(); i++)
    {
        if (v[i] > v[i - 1])
            cnt++;
        else
            cnt = 0;
        if (cnt >= 3)
        {
            flag = true;
            sungmin = sungmin * v[i];
            break;
        }
    }

    if (!flag)
        sungmin = N + (sungmin * v[13]);

    if (sungmin > junhyeon)
        cout << "TIMING";
    else if (sungmin < junhyeon)
        cout << "BNP";
    else
        cout << "SAMESAME";
}