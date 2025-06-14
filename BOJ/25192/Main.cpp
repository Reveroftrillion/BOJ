#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int gomgom = 0;
    set<string> kakao;
    for (int i = 0; i < k; i++)
    {
        string str;
        cin >> str;
        if (str == "ENTER")
        {
            gomgom += kakao.size();
            kakao.clear();
        }
        else
        {
            kakao.insert(str);
        }
    }
    gomgom += kakao.size();
    cout << gomgom << endl;
}