#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const vector<vector<string>> digit_patterns = {
    {"###", "#.#", "#.#", "#.#", "###"},
    {"..#", "..#", "..#", "..#", "..#"},
    {"###", "..#", "###", "#..", "###"},
    {"###", "..#", "###", "..#", "###"},
    {"#.#", "#.#", "###", "..#", "..#"},
    {"###", "#..", "###", "..#", "###"},
    {"###", "#..", "###", "#.#", "###"},
    {"###", "..#", "..#", "..#", "..#"},
    {"###", "#.#", "###", "#.#", "###"},
    {"###", "#.#", "###", "..#", "###"}};

bool is_valid(const vector<string> &input_pat, const vector<string> &ref_pat)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (input_pat[i][j] == '#' && ref_pat[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<string>> input_digits(4, vector<string>(5));
    for (int i = 0; i < 5; ++i)
    {
        cin >> input_digits[0][i] >> input_digits[1][i] >> input_digits[2][i] >> input_digits[3][i];
    }

    for (int h = 0; h < 24; ++h)
    {
        for (int m = 0; m < 60; ++m)
        {
            int h1 = h / 10;
            int h2 = h % 10;
            int m1 = m / 10;
            int m2 = m % 10;

            if (is_valid(input_digits[0], digit_patterns[h1]) &&
                is_valid(input_digits[1], digit_patterns[h2]) &&
                is_valid(input_digits[2], digit_patterns[m1]) &&
                is_valid(input_digits[3], digit_patterns[m2]))
            {
                cout << setfill('0') << setw(2) << h << ":"
                     << setfill('0') << setw(2) << m << endl;
                return 0;
            }
        }
    }

    return 0;
}