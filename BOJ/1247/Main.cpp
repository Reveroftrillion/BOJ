#include <iostream>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const long long LL_MAX = numeric_limits<long long>::max();
    const long long LL_MIN = numeric_limits<long long>::min();

    int t = 3;
    while (t--)
    {
        int n;
        cin >> n;

        long long current_sum = 0;
        int overflow_count = 0;

        for (int i = 0; i < n; ++i)
        {
            long long s;
            cin >> s;

            if (s > 0)
            {
                if (current_sum > LL_MAX - s)
                {
                    overflow_count++;
                }
            }
            else if (s < 0)
            {
                if (current_sum < LL_MIN - s)
                {
                    overflow_count--;
                }
            }
            current_sum += s;
        }

        if (overflow_count > 0)
        {
            cout << "+\n";
        }
        else if (overflow_count < 0)
        {
            cout << "-\n";
        }
        else
        {
            if (current_sum > 0)
            {
                cout << "+\n";
            }
            else if (current_sum < 0)
            {
                cout << "-\n";
            }
            else
            {
                cout << "0\n";
            }
        }
    }

    return 0;
}