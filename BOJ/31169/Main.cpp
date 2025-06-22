#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;
    while (z--)
    {
        string s;
        cin >> s;
        for (char &c : s)
            c = 'a' + (c - 'a' + 13) % 26;
        cout << s << '\n';
    }
    return 0;
}
