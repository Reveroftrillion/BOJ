#include <iostream>
#include <string>
using namespace std; // 얘는 unsigned char를 안 쓰면 오버플로우가 발생한다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    for (char &c : str)
    {
        unsigned char uc = static_cast<unsigned char>(c);
        if (isupper(uc))
        {
            c = char((uc - 'A' + 13) % 26 + 'A');
        }
        else if (islower(uc))
        {
            c = char((uc - 'a' + 13) % 26 + 'a');
        }
        }
    cout << str << endl;
}