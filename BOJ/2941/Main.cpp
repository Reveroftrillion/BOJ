#include <iostream>
#include <string>
using namespace std;

int croatia(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (i + 2 < str.size() && str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
        {
            cnt++;
            i += 2;
        }
        /* if (i + 2 < str.size() && str.substr(i, 3) == "dz=")
        {
            cnt++;
            i += 2;
        } */

        else if (i + 1 < str.size())
        {
            string pair = str.substr(i, 2); // 2개로 잘라서 확인하기. dz=도 똑같이 할 수 있다. => 주석 참고
            if (pair == "c=" || pair == "c-" || pair == "d-" || pair == "lj" || pair == "nj" || pair == "s=" || pair == "z=")
            {
                cnt++;
                i += 1;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    string str;
    cin >> str;
    cout << croatia(str) << endl;
}