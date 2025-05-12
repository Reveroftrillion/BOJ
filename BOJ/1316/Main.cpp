#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int answer = 0;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;

        bool group = true;
        bool alphabet[26] = {false};
        char before = 0;

        for (char c : str)
        {
            if (c != before)
            {
                if (alphabet[c - 'a']) // 이렇게 char단위에서 a를 빼주면 0이 되는걸 이용 잘 하자.
                {
                    group = false;
                    break;
                }

                alphabet[c - 'a'] = true;
                before = c;
            }
        }
        if (group)
        {
            answer++;
        }
    }
    cout << answer << '\n';
}