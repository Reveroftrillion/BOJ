#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// dp 쓰는 건데 너무 큰 수라 dp[i] = dp[i - 1] + 2 * dp[i - 2]를 구현하는 방법이 핵심.
// 처음에는 boost를 써야하는 줄 알았으나, 문자열로 바꿔서 풀면 된다는 방법을 얻음.
// 2 곱하는 것과 덧셈을 전부 문자열로 하는 방법 구현.

string string_multiply_by_two(string n)
{
    string result = "";
    int carry = 0;

    for (int i = n.length() - 1; i >= 0; i--)
    {
        int digit = n[i] - '0';
        int product = digit * 2 + carry;

        carry = product / 10;
        result += to_string(product % 10);
    }

    if (carry > 0)
    {
        result += to_string(carry);
    }

    reverse(result.begin(), result.end());
    return result;
}

string string_add(string a, string b)
{
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        carry = sum / 10;
        result += to_string(sum % 10);
    }

    reverse(result.begin(), result.end());
    return result;
}

void solve()
{
    vector<int> inputs;
    int n;
    while ((cin >> n))
    {
        inputs.push_back(n);
    }

    if (inputs.empty())
        return;

    int maxn = 0;
    for (int x : inputs)
    {
        if (x > maxn)
            maxn = x;
    }

    vector<string> D(maxn + 1);

    D[0] = "1";

    if (maxn >= 1)
    {
        D[1] = "1";
    }

    for (int i = 2; i <= maxn; ++i)
    {
        string term2 = string_multiply_by_two(D[i - 2]);
        D[i] = string_add(D[i - 1], term2);
    }

    for (int x : inputs)
    {
        cout << D[x] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}