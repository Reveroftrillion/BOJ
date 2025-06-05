#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> ATM(t);
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        ATM[i] += k;
    }
    sort(ATM.begin(), ATM.end());
    for (int i = 0; i < t; i++)
    {
        sum += ATM[i] * (t - i);
    }
    cout << sum << '\n';
}