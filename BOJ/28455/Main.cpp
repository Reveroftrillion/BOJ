#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int union_level(int k)
{
    int num = 0;
    if (k >= 60)
        num++;
    if (k >= 100)
        num++;
    if (k >= 140)
        num++;
    if (k >= 200)
        num++;
    if (k >= 250)
        num++;
    return num;
}

int main()
{
    int p;
    cin >> p;
    if (p < 42)
    {
        int answer = 0;
        int union_answer = 0;
        for (int i = 0; i < p; i++)
        {
            int al;
            cin >> al;
            answer += al;
            union_answer += union_level(al);
        }
        cout << answer << " " << union_answer << endl;
    }
    else
    {
        int answer = 0;
        int union_answer = 0;
        vector<int> all_case;
        for (int i = 0; i < p; i++)
        {
            int io;
            cin >> io;
            all_case.push_back(io);
        }
        sort(all_case.begin(), all_case.end(), greater<int>());
        for (int j = 0; j <= 41; j++)
        {
            int qp;
            qp = all_case[j];
            answer += qp;
            union_answer += union_level(qp);
        }
        cout << answer << " " << union_answer << endl;
    }
}