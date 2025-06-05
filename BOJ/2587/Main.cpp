#include <bits/stdc++.h>
using namespace std;

int main()
{
    int average = 0;
    vector<int> chungang;
    for (int i = 0; i < 5; i++)
    {
        int t;
        cin >> t;
        average += t;
        chungang.push_back(t);
    }
    average /= 5;
    sort(chungang.begin(), chungang.end());
    cout << average << endl;
    cout << chungang[2] << endl;
}