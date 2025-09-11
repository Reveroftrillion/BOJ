#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;

        set<int> student_list;
        for (int i = 0; i < K; ++i)
        {
            int student_id;
            cin >> student_id;
            student_list.insert(student_id);
        }

        int N;
        cin >> N;

        int best_student_id = -1;
        int best_hour = 6;
        int best_minute = 1;
        set<int> disqualified_students;

        for (int i = 0; i < N; ++i)
        {
            int participant_id, hour, minute;
            cin >> participant_id >> hour >> minute;

            if (student_list.count(participant_id))
            {
                if (hour == -1 || hour > 6 || (hour == 6 && minute > 0))
                {
                    disqualified_students.insert(participant_id);
                }
                else
                {
                    if (hour < best_hour || (hour == best_hour && minute < best_minute))
                    {
                        best_hour = hour;
                        best_minute = minute;
                        best_student_id = participant_id;
                    }
                }
            }
        }

        int certified_count = K - disqualified_students.size();

        cout << best_student_id << " " << certified_count << endl;
    }

    return 0;
}