#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;
    int distinct_required = (B + 1) / 2;
    int N = max(A, distinct_required);
    vector<string> words;
    words.reserve(distinct_required);
    for (int i = 0; i < distinct_required; ++i)
    {
        int x = i;
        string s;
        do
        {
            s.push_back(char('a' + (x % 26)));
            x /= 26;
        } while (x > 0);
        words.push_back(s);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << words[i % distinct_required];
        if (i + 1 < N)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}