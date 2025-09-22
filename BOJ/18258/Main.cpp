#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    queue<int> what;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int a;
            cin >> a;
            what.push(a);
        }
        else if (str == "front")
        {
            if (what.empty())
                cout << -1 << '\n';
            else
                cout << what.front() << '\n';
        }
        else if (str == "back")
        {
            if (what.empty())
                cout << -1 << '\n';
            else
                cout << what.back() << '\n';
        }
        else if (str == "pop")
        {
            if (what.empty())
                cout << -1 << '\n';
            else
            {
                cout << what.front() << '\n';
                what.pop();
            }
        }
        else if (str == "size")
        {
            cout << what.size() << '\n';
        }
        else if (str == "empty")
        {
            cout << what.empty() << '\n';
        }
    }
    return 0;
}
