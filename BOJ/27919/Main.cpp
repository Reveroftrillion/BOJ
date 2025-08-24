#include <iostream>
#include <string>
#include <map>

using namespace std;

void solve()
{
    string V;
    cin >> V;

    map<char, int> counts;
    for (char c : V)
    {
        counts[c]++;
    }

    int number_of_uc = counts['U'] + counts['C'];
    int number_of_dp = counts['D'] + counts['P'];

    string result = "";

    if (number_of_uc > (number_of_dp + 1) / 2)
    {
        result += 'U';
    }

    if (number_of_dp > 0)
    {
        result += 'D';
    }

    if (number_of_dp > 0)
    {
        result += 'P';
    }

    if (result.empty())
    {
        cout << 'C' << endl;
    }
    else
    {
        cout << result << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}