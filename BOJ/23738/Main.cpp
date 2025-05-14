#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string result;
    for (char c : str)
    {
        char k = tolower(c);
        if (k == 'b')
        {
            result += 'v';
        }
        else if (k == 'e')
        {
            result += "ye";
        }
        else if (k == 'h')
        {
            result += 'n';
        }
        else if (k == 'p')
        {
            result += 'r';
        }
        else if (k == 'c')
        {
            result += 's';
        }
        else if (k == 'y')
        {
            result += 'u';
        }
        else if (k == 'x')
        {
            result += 'h';
        }
        else
        {
            result += k;
        }
    }
    cout << result << endl;
}