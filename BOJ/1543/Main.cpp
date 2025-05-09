#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, f_str;
    getline(cin, str); // getline으로 공백을 포함해서 읽기
    getline(cin, f_str);
    int cnt = 0;
    size_t position = 0; // 배열이나 문자열의 크기를 반환하는 부호없는 정수형 타입

    if (f_str.empty())
    {
        cout << 0;
        return 0;
    }

    while ((position = str.find(f_str, position)) != string::npos) // string::npos -> 문자열을 찾지 못했다는 의미미
    {
        cnt++;
        position += f_str.size();
    }
    cout << cnt << endl;
}