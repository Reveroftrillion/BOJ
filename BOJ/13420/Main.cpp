#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    cin.ignore(); // getline 쓰려면 이거 중요하다.
    for (int i = 0; i < k; i++)
    {
        string str;
        getline(cin, str);

        istringstream iss(str); // str을 cin 처럼 쓰게 만들어줌
        vector<string> gusung;
        string word;

        while (iss >> word)
        {
            gusung.push_back(word);
        }

        if (gusung[1] == "+")
        {
            if (stoll(gusung[0]) + stoll(gusung[2]) == stoll(gusung[4]))
            {
                cout << "correct" << '\n';
            }
            else
            {
                cout << "wrong answer" << '\n';
            }
        }

        if (gusung[1] == "-")
        {
            if (stoll(gusung[0]) - stoll(gusung[2]) == stoll(gusung[4]))
            {
                cout << "correct" << '\n';
            }
            else
            {
                cout << "wrong answer" << '\n';
            }
        }

        if (gusung[1] == "*")
        {
            if (stoll(gusung[0]) * stoll(gusung[2]) == stoll(gusung[4]))
            {
                cout << "correct" << '\n';
            }
            else
            {
                cout << "wrong answer" << '\n';
            }
        }

        if (gusung[1] == "/")
        {
            if (stoll(gusung[0]) / stoll(gusung[2]) == stoll(gusung[4]))
            {
                cout << "correct" << '\n';
            }
            else
            {
                cout << "wrong answer" << '\n';
            }
        }
        }
}