#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        map<string, int> clothes;
        for (int j = 0; j < n; j++)
        {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }

        int answer = 1;
        for (auto it = clothes.begin(); it != clothes.end(); it++) // value 값들만 곱해주기 위함.
        {
            answer *= (it->second + 1);
        }
        answer -= 1;
        cout << answer << endl;
    }
}