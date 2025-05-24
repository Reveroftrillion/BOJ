#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int current = 1;
    vector<char> plusminus;
    stack<int> realstack;
    bool okay = true;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        while (k >= current)
        {
            realstack.push(current);
            plusminus.push_back('+');
            current++;
        }
        if (realstack.top() == k)
        {
            realstack.pop();
            plusminus.push_back('-');
        }
        else
        {
            okay = false;
        }
    }
    if (okay)
    {
        for (char c : plusminus)
        {
            cout << c << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
}