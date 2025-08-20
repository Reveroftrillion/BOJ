#include <iostream>
using namespace std;

int main()
{
    string first_str, second_str;
    int cross_A(-1), cross_B(-1);
    bool flag = false;
    cin >> first_str >> second_str;

    for (int i = 0; i < first_str.length(); i++)
    {
        for (int j = 0; j < second_str.length(); j++)
        {
            if (first_str[i] == second_str[j])
            {
                cross_A = i;
                cross_B = j;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    for (int i = 0; i < second_str.length(); i++)
    {
        if (i == cross_B)
        {
            cout << first_str << '\n';
            continue;
        }
        for (int j = 0; j < first_str.length(); j++)
        {
            if (j == cross_A)
            {
                cout << second_str[i];
            }
            else
            {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}