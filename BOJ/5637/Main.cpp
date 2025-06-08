#include <bits/stdc++.h>
using namespace std;

bool is_valid_char(char c)
{
    return isalpha(c) || c == '-';
}

int main()
{
    string word, longest;
    while (cin >> word)
    {
        string temp = "";
        for (char c : word)
        {
            if (is_valid_char(c))
            {
                temp += tolower(c);
            }
        }

        if (temp == "e-n-d")
            break;

        if (temp.size() > longest.size())
        {
            longest = temp;
        }
    }

    cout << longest << '\n';
    return 0;
}