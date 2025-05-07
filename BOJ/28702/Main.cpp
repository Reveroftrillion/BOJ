#include <iostream>
#include <string> // stoi 쓰려면 이거 include 해주자.
using namespace std;

int main()
{
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    int want = 0;
    if (str1 != "Fizz" && str1 != "Buzz" && str1 != "FizzBuzz")
    {
        want = stoi(str1) + 3;
    }
    if (str2 != "Fizz" && str2 != "Buzz" && str2 != "FizzBuzz")
    {
        want = stoi(str2) + 2;
    }
    if (str3 != "Fizz" && str3 != "Buzz" && str3 != "FizzBuzz")
    {
        want = stoi(str3) + 1;
    }
    if (want % 3 == 0 && want % 5 != 0)
    {
        cout << "Fizz" << endl;
    }
    else if (want % 3 != 0 && want % 5 == 0)
    {
        cout << "Buzz" << endl;
    }
    else if (want % 3 == 0 && want % 5 == 0)
    {
        cout << "FizzBuzz" << endl;
    }
    else
    {
        cout << want << endl;
    }
    return 0;
}