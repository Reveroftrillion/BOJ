#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int num = t;
    int result = 0;
    int digit;

    digit = num / 6561;
    result = digit;
    num %= 6561;

    digit = num / 729;
    result = result * 10 + digit;
    num %= 729;

    digit = num / 81;
    result = result * 10 + digit;
    num %= 81;

    digit = num / 9;
    result = result * 10 + digit;
    num %= 9;

    digit = num;
    result = result * 10 + digit;

    cout << result << endl;
    return 0;
}
