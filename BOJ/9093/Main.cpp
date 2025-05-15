#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore(); // getline 쓰려면 버퍼 비위줘야해.

    for (int i = 0; i < t; i++)
    {
        string str;
        getline(cin, str);
        string array[1000];
        stringstream ss(str); // 문자열을 입력 스트림처럼 사용
        string word;          // ss로 문자열을 입력으로 받아오고 저장해 놓을 곳 지정
        int index = 0;

        while (ss >> word) // >>를 통해 공백을 기준으로 문자열을 끊어서 가져옴
        {
            array[index] = word;
            index++;
        }

        for (int j = 0; j < index; j++)
        {
            string &str1 = array[j]; // &를 통해 alias 만들어서 array에 직접 접근해서 바꾸기
            int length = str1.size();
            for (int k = 0; k < length / 2; k++)
            {
                char c = str1[k];
                str1[k] = str1[length - 1 - k];
                str1[length - 1 - k] = c;
            }
            cout << str1 << " ";
        }
        cout << '\n';
    }
}