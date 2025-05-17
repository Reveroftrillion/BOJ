#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    queue<int> q;
    for (int i = 1; i <= a; i++)
    {
        q.push(i);
    }

    cout << "<";
    while (!q.empty())
    {
        for (int i = 1; i < b; i++)
        {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if (!q.empty())
            cout << ", ";
    }
    cout << ">\n";

    return 0;
}
