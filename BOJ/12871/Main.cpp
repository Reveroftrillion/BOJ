#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    string fstr1, fstr2;
    int temp = LCM(str1.size(), str2.size());
    for (int i = 0; i < temp / str1.size(); i++)
    {
        fstr1 += str1;
    }
    for (int i = 0; i < temp / str2.size(); i++)
    {
        fstr2 += str2;
    }
    if (fstr1 == fstr2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}