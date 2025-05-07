#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string str;
    cin >> str;
    for (int i = t - 5; i < t; i++)
    {
        cout << str[i];
    }
    cout << endl;
    return 0;
}