#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] > 91)
        {
            str[i] -= 32;
        }
        else
        {
            str[i] += 32;
        }
    }
    cout << str << endl;
}