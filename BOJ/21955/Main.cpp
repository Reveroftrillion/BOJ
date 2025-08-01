#include <iostream>
#include <string>
using namespace std;

string str;
int main()
{
    cin >> str;
    int _Pivot = str.length() * 0.5f;
    cout << str.substr(0, _Pivot) << " " << str.substr(_Pivot, str.length());
    return 0;
}