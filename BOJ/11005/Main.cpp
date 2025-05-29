#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;

    string result = "";

    while (n > 0)
    {
        int remainder = n % b;
        if (remainder < 10)
        {
            result += (remainder + '0');
        }
        else
        {
            result += (remainder - 10 + 'A');
        }
        n /= b;
    }

    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
