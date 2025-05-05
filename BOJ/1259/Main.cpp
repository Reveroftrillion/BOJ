#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int t;
        cin >> t;
        if (t == 0)
            break;

        string number = to_string(t);
        int v = number.size() - 1;
        bool pelindrome = true;
        for (int i = 0; i < v; i++)
        {
            if (number[i] != number[v - i])
            {
                pelindrome = false;
            }
        }
        if (pelindrome)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
