#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct StudentInfo
{
    string name;
    int fee;
};

bool compareStudents(const StudentInfo &a, const StudentInfo &b)
{
    if (a.fee != b.fee)
    {
        return a.fee > b.fee;
    }
    return a.name < b.name;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> total_call_time;

    for (int i = 0; i < n; ++i)
    {
        string time_str, name;
        cin >> time_str >> name;

        int hours = stoi(time_str.substr(0, 2));
        int minutes = stoi(time_str.substr(3, 2));
        int duration_in_minutes = hours * 60 + minutes;

        total_call_time[name] += duration_in_minutes;
    }

    vector<StudentInfo> students;

    for (auto const &pair : total_call_time)
    {
        string name = pair.first;
        int total_minutes = pair.second;

        int fee = 10;

        if (total_minutes > 100)
        {
            int extra_minutes = total_minutes - 100;
            int units = (extra_minutes + 49) / 50;
            fee += units * 3;
        }

        students.push_back({name, fee});
    }

    sort(students.begin(), students.end(), compareStudents);

    for (const auto &student : students)
    {
        cout << student.name << " " << student.fee << "\n";
    }

    return 0;
}