#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> table;

    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        table.push_back(k);
    }

    table.push_back(table[0]);

    int ascending = 0;
    for (int j = 0; j < N; j++)
    {
        if (table[j] >= table[j + 1])
        {
            ascending++;
        }
    }

    cout << ascending << endl;

    return 0;
}