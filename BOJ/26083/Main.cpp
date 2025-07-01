#include <bits/stdc++.h>
using namespace std;

/* 월별 일수, 1-based 인덱스 */
int mdays(int y, int m)
{
    if (m == 2)
        return (y % 4 == 0) ? 29 : 28;
    return (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) ? 31 : (m == 4 || m == 6 || m == 9 || m == 11) ? 30
                                                                                                                                 : 0; // 0 → invalid month
}

bool valid(int y, int m, int d)
{
    if (y < 2000 || y > 2099)
        return false;
    if (m < 1 || m > 12)
        return false;
    int last = mdays(y, m);
    return d >= 1 && d <= last;
}

struct Date
{
    int y, m, d;
    bool operator<(const Date &o) const
    {
        if (y != o.y)
            return y < o.y;
        if (m != o.m)
            return m < o.m;
        return d < o.d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Y, M, D;
    if (!(cin >> Y >> M >> D))
        return 0;
    Date today{2000 + Y, M, D};

    int N;
    cin >> N;
    while (N--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        vector<Date> v;

        // yyyy/mm/dd
        Date d1{2000 + A, B, C};
        if (valid(d1.y, d1.m, d1.d))
            v.push_back(d1);

        // dd/mm/yyyy
        Date d2{2000 + C, B, A};
        if (valid(d2.y, d2.m, d2.d))
            v.push_back(d2);

        // mm/dd/yyyy
        Date d3{2000 + C, A, B};
        if (valid(d3.y, d3.m, d3.d))
            v.push_back(d3);

        if (v.empty())
        {
            cout << "invalid\n";
            continue;
        }

        bool allSafe = true;
        for (auto &dt : v)
            if (dt < today)
            {
                allSafe = false;
                break;
            }

        cout << (allSafe ? "safe\n" : "unsafe\n");
    }
    return 0;
}
