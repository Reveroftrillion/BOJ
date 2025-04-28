#include <iostream>
using namespace std;

int main()
{
    string c;
    cin >> c;
    char first;
    first = c[0]; // string은 [0], [1] 등으로 한 글자씩 나눌 수 있다.
    int bowl = 10;
    for (int i = 1; i < c.size(); i++) // 문자열 끝나면 for문 종료되도록 c.size함수를 통해 문자열의 길이를 받아온다.
    {
        if (c[i] == first)
        {
            bowl += 5;
        }
        else if (c[i] != first)
        {
            bowl += 10;
            first = c[i];
        }
    }
    cout << bowl << endl;
}