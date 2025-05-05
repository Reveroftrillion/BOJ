#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        int last;
        last = str.size() - 1; // 스트링의 마지막 인덱스는 str.size() - 1이다.
        cout << str[0] << str[last] << endl;
    }
}