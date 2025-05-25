#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> jiphap(20, 0);
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            int k;
            cin >> k;

            jiphap[k - 1] = 1;
        }
        else if (str == "remove")
        {
            int k;
            cin >> k;
            jiphap[k - 1] = 0;
        }
        else if (str == "check")
        {
            int k;
            cin >> k;
            if (jiphap[k - 1] > 0)
            {
                cout << "1" << '\n';
            }
            else if (jiphap[k - 1] == 0)
            {
                cout << "0" << '\n';
            }
        }
        else if (str == "toggle")
        {
            int k;
            cin >> k;
            if (jiphap[k - 1] == 0)
            {
                jiphap[k - 1]++;
            }
            else
            {
                jiphap[k - 1]--;
            }
        }
        else if (str == "all")
        {
            fill(jiphap.begin(), jiphap.end(), 1); // for문 보다 fill 함수 쓰는게 더 낫다.
        }
        else if (str == "empty")
        {
            fill(jiphap.begin(), jiphap.end(), 0);
        }
    }
}