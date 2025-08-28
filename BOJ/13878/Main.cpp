#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> value_map;
map<char, char> substitutions;

void initialize_maps()
{
    string valid_digits = "0123456789ACDEFHJKLMNPRTVWX";
    for (int i = 0; i < valid_digits.length(); ++i)
    {
        value_map[valid_digits[i]] = i;
    }
    substitutions['B'] = '8';
    substitutions['G'] = 'C';
    substitutions['I'] = '1';
    substitutions['O'] = '0';
    substitutions['Q'] = '0';
    substitutions['S'] = '5';
    substitutions['U'] = 'V';
    substitutions['Y'] = 'V';
    substitutions['Z'] = '2';
}

void solve()
{
    int k;
    string ucn;
    cin >> k >> ucn;

    string clean_ucn = "";
    for (char c : ucn)
    {
        if (substitutions.count(c))
        {
            clean_ucn += substitutions[c];
        }
        else
        {
            clean_ucn += c;
        }
    }

    vector<int> d(8);
    for (int i = 0; i < 8; ++i)
    {
        d[i] = value_map[clean_ucn[i]];
    }

    int weights[] = {2, 4, 5, 7, 8, 10, 11, 13};
    long long sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += (long long)weights[i] * d[i];
    }

    int calculated_check_val = sum % 27;
    int given_check_val = value_map[clean_ucn[8]];

    cout << k << " ";
    if (calculated_check_val != given_check_val)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        long long decimal_value = 0;
        for (int i = 0; i < 8; ++i)
        {
            decimal_value = decimal_value * 27 + d[i];
        }
        cout << decimal_value << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    initialize_maps();
    int p;
    cin >> p;
    while (p--)
    {
        solve();
    }

    return 0;
}
