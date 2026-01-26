#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    unordered_set<string> real;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        real.insert(str);
    }
    int cnt = 0;
    for (int j = 0; j < M; j++)
    {
        string check;
        cin >> check;
        if (real.count(check))
            cnt++;
    }
    cout << cnt << endl;
}