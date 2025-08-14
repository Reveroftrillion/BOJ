#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_k_base(long long num, int k)
{
    if (num == 0)
    {
        return "0";
    }
    string result = "";
    while (num > 0)
    {
        result += to_string(num % k);
        num /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int k;
    cin >> n >> k;

    string n_k_base_str = to_k_base(n, k);

    long long total_sum = 0;
    string current_part = "";

    for (char digit : n_k_base_str)
    {
        if (digit == '0')
        {
            if (!current_part.empty())
            {
                total_sum += stoll(current_part);
                current_part = "";
            }
        }
        else
        {
            current_part += digit;
        }
    }

    if (!current_part.empty())
    {
        total_sum += stoll(current_part);
    }

    string final_result = to_k_base(total_sum, k);

    cout << final_result << endl;

    return 0;
}