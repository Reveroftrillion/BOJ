#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 이 문제는 스택을 사용해야 한다.
// 스택은 한쪽 방향으로만 자료를 넣고 뺴는 구조 = Last In First Out 구조
// push : 맨 위에 넣음, pop : 맨 위 꺼 제거, top : 맨 위 꺼 확인

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    while (true)
    {
        getline(cin, str);

        if (str == ".")
        {
            break;
        }

        stack<char> world;
        bool balance = true;

        for (char c : str)
        {
            if (c == '(' || c == '[')
            {
                world.push(c);
            }

            else if (c == ')')
            {
                if (world.empty() || world.top() != '(')
                {
                    balance = false;
                    break;
                }
                world.pop();
            }

            else if (c == ']')
            {
                if (world.empty() || world.top() != '[')
                {
                    balance = false;
                    break;
                }
                world.pop();
            }
        }

        if (balance && world.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}