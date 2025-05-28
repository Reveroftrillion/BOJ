#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int sum = 0;
    stack<int> coin;
    for (int i = 0; i < a; i++)
    {
        int k;
        cin >> k;
        coin.push(k);
    }
    while (b > 0)
    {
        for (int j = 0; j < a; j++)
        {
            if (b / coin.top() > 0)
            {
                sum += b / coin.top();
                b %= coin.top();
                coin.pop();
            }
            else
            {
                coin.pop();
            }
        }
    }
    cout << sum << '\n';
}