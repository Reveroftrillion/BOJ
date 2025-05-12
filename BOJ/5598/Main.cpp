#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for (char &c : str)
    {
        c -= 3;
        if (c < 'A')
        {
            c += 26;
        }
    }
    cout << str << endl;
}