#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c, f, h, p;

    while (cin >> c >> f >> h >> p && (c != 0 || f != 0 || h != 0 || p != 0))
    {
        double min_f_val = (f == 0) ? 0.0 : f - 0.5;
        double min_h_val = (h == 0) ? 0.0 : h - 0.5;
        double min_p_val = (p == 0) ? 0.0 : p - 0.5;

        double max_f_val = f + 0.5;
        double max_h_val = h + 0.5;
        double max_p_val = p + 0.5;

        double min_total_cal = 9.0 * min_f_val + 4.0 * min_h_val + 4.0 * min_p_val;
        double max_total_cal = 9.0 * max_f_val + 4.0 * max_h_val + 4.0 * max_p_val;

        double min_target_cal = c - 0.5;
        double max_target_cal = c + 0.5;

        if (min_total_cal < max_target_cal && min_target_cal < max_total_cal)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}