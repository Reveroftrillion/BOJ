#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> borrow(32, 0);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++)
        {
            borrow[j]++;
        }
    }
    int book;
    cin >> book;
    bool want = true;
    for (int i = 0; i < 32; i++)
    {
        if (borrow[i] > book)
        {
            want = false;
            break;
        }
    }
    if (want)
    {
        cout << 1 << '\n';
    }
    else if (!want)
    {
        cout << 0 << '\n';
    }
}