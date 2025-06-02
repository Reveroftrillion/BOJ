#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string boss = "";
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        if (str.size() == 3)
        {
            if (boss == "" || str < boss)
            {
                boss = str;
            }
        }
    }
    cout << boss << endl;
}