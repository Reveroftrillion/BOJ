#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string binary(string a, string b)
{
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result += (sum % 2) + '0'; // string으로 바꿔서 더해줌
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());

    size_t pos = result.find_first_not_of('0'); // 0이 아닌 처음 부분을 pos에 저장

    return pos != string::npos ? result.substr(pos) : "0"; // pos부터 잘라서 출력하되 0000이면 0으로 출력
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string a, b;
        cin >> a >> b;
        cout << binary(a, b) << endl;
    }
    return 0;
}
