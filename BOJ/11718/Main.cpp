#include <iostream>
#include <string>
using namespace std;

int main()
{
    string c;
    while (getline(cin, c))
    { // 문자열을 공백을 포함해서 입력 받을 때에는 getline 함수를 사용해야 한다. 얘는 EOF (입력 끝)까지 해준다.
        cout << c << endl;
    }
    return 0;
}
