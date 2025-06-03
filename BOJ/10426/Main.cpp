#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int a;
    cin >> str;
    cin >> a;
    stringstream ss(str);
    vector<string> date;
    string str1;
    while (getline(ss, str1, '-'))
    {
        date.push_back(str1);
    }
    int year = stoi(date[0]);
    int month = stoi(date[1]);
    int day = stoi(date[2]);
    day += a - 1;
    while (true)
    {
        int days_in_month;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            days_in_month = 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            days_in_month = 30;
        else
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                days_in_month = 29;
            else
                days_in_month = 28;
        }

        if (day < days_in_month + 1)
            break;

        day -= days_in_month;
        month++;
        if (month >= 13)
        {
            month = 1;
            year++;
        }
    }
    cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << '\n';
}