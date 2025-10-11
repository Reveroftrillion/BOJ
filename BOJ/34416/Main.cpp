#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int pos;
    int m;
    if (!(cin >> n))
        return 0;
    cin >> pos;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (pos == a)
            pos = b;
        else if (pos == b)
            pos = a;
    }

    cout << pos << '\n';
    return 0;
}
