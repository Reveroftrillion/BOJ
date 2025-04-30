#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string old_name, young_name;
    int old_day = 32, old_month = 13, old_year = 2011;
    int young_day = 0, young_month = 0, young_year = 1989;
    for (int i = 0; i < t; i++)
    {
        int day, month, year;
        string name;
        cin >> name;
        cin >> day >> month >> year; // 여기서 year -> month -> day 순으로 비교하면 year만 작을 때를 잡지 못한다.
        if (year < old_year ||
            (year == old_year && month < old_month) ||
            (year == old_year && month == old_month && day < old_day))
        {
            old_day = day;
            old_month = month;
            old_year = year;
            old_name = name;
        }

        if (year > young_year ||
            (year == young_year && month > young_month) ||
            (year == young_year && month == young_month && day > young_day))
        {
            young_day = day;
            young_month = month;
            young_year = year;
            young_name = name;
        }
    }
    cout << young_name << endl;
    cout << old_name << endl;
}