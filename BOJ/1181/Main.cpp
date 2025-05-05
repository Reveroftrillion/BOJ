#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b)
{ // const를 통해 수정 불가능, string&로 메모리 효율 up.
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a < b;
}

int main()
{
    int t;
    cin >> t;
    vector<string> array;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        bool duplicate = false;

        for (int j = 0; j < array.size(); j++) // arrary가 지금 비어있는 상태이므로, j < t가 아니라 j < array.size()로 해야함
        {
            if (array[j] == str)
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
        {
            array.push_back(str);
        }
    }
    // sort()만 쓰면 문자열은 오름차순으로 알파벳 순서만 고려한다. 문자열 길이도 고려해야하기에 compare라는 함수를 만들자.
    sort(array.begin(), array.end(), compare);
    for (int k = 0; k < array.size(); k++)
    {
        cout << array[k] << endl;
    }
}