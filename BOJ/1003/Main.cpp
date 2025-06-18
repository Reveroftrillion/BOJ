#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    int cnt_zero[41] = {0};
    int cnt_one[41] = {0};

    cnt_zero[0] = 1;
    cnt_one[1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        cnt_zero[i] = cnt_zero[i - 1] + cnt_zero[i - 2];
        cnt_one[i] = cnt_one[i - 1] + cnt_one[i - 2];
    }

    while (k--)
    {
        int n;
        cin >> n;
        cout << cnt_zero[n] << " " << cnt_one[n] << endl;
    }
}