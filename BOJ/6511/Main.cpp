#include <iostream>
using namespace std;

int main()
{
    long long n, m, c;
    while (cin >> n >> m >> c && (n != 0 || m != 0 || c != 0))
    {
        long long rows = n - 7;
        long long cols = m - 7;
        long long total_subgrids = rows * cols;

        bool count_even_sum = (((n + m) % 2) == 1 && c == 0) || (((n + m) % 2) == 0 && c == 1);

        long long even_count, odd_count;
        if (total_subgrids % 2 == 0)
        {
            even_count = odd_count = total_subgrids / 2;
        }
        else
        {
            long long even_rows = rows / 2;
            long long odd_rows = (rows + 1) / 2;
            long long even_cols = cols / 2;
            long long odd_cols = (cols + 1) / 2;

            even_count = even_rows * even_cols + odd_rows * odd_cols;
            odd_count = even_rows * odd_cols + odd_rows * even_cols;
        }

        if (count_even_sum)
        {
            cout << even_count << endl;
        }
        else
        {
            cout << odd_count << endl;
        }
    }
    return 0;
}