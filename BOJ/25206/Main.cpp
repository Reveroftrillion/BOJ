#include <iostream>
#include <string>
using namespace std;

int main()
{
    double sum = 0.0;
    double total = 0.0;
    double n_include = 0.0;
    for (int i = 0; i < 20; i++)
    {
        string str;
        double pt;
        string str1;
        cin >> str >> pt >> str1;
        if (str1 == "A+")
        {
            sum += pt * 4.5;
            total += pt;
        }
        else if (str1 == "A0")
        {
            sum += pt * 4.0;
            total += pt;
        }
        else if (str1 == "B+")
        {
            sum += pt * 3.5;
            total += pt;
        }
        else if (str1 == "B0")
        {
            sum += pt * 3.0;
            total += pt;
        }
        else if (str1 == "C+")
        {
            sum += pt * 2.5;
            total += pt;
        }
        else if (str1 == "C0")
        {
            sum += pt * 2.0;
            total += pt;
        }
        else if (str1 == "D+")
        {
            sum += pt * 1.5;
            total += pt;
        }
        else if (str1 == "D0")
        {
            sum += pt * 1.0;
            total += pt;
        }
        else if (str1 == "F")
        {
            sum += pt * 0.0;
            total += pt;
        }
    }
    double answer = sum / (total - n_include);
    cout.precision(6);
    cout << fixed; // precision으로 소수점 어디까지 출력하고 싶은지 결정하고 fixed로 이제부터 cout할 때마다 적용하도록 설정
                   // fixed를 풀고 싶으면 cout.unsetf(ios::fixed)를 이용
    cout << answer << endl;
}