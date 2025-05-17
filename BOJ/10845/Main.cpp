#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int t;
    cin >> t;
    deque<int> queue;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int j;
            cin >> j;
            queue.push_back(j);
        }
        if (str == "pop")
        {
            if (!queue.empty())
            {
                cout << queue.front() << '\n';
                queue.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        if (str == "size")
        {
            cout << queue.size() << '\n';
        }
        if (str == "empty")
        {
            cout << (queue.empty() ? 1 : 0) << '\n'; // 삼중 연산자 활용하는 걸 검토해보자.
        }
        if (str == "front")
        {
            cout << (queue.empty() ? -1 : queue.front()) << '\n';
        }
        if (str == "back")
        {
            cout << (queue.empty() ? -1 : queue.back()) << '\n'; // queue에서 size - 1로 접근하는 건 런타임 에러 확률 up
        }
    }
}