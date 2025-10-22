#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    size_t pos1 = str.find('/');
    size_t pos2 = str.rfind('/');

    int k = stoi(str.substr(0, pos1));
    int d = stoi(str.substr(pos1 + 1, pos2 - pos1 - 1));
    int a = stoi(str.substr(pos2 + 1));

    if (k + a < d || d == 0)
        cout << "hasu";
    else
        cout << "gosu";

    return 0;
}
