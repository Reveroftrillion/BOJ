#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    int f = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        if (i % 2 == 0)
        {
            f += v[i];
        }
        else
        {
            f -= v[i];
        }
    }

    f /= 2;
    cout << f << "\n";

    for (int i = 0; i < n - 1; ++i)
    {
        f = v[i] - f;
        cout << f << "\n";
    }

    return 0;
}
