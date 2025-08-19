#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long T;
    cin >> N >> T;

    long long x = 0;
    long long y = 0;
    long long current_time = 0;
    long long vx = 1;
    long long vy = 0;

    for (int i = 0; i < N; ++i)
    {
        long long turn_time;
        string direction;
        cin >> turn_time >> direction;

        long long time_segment = turn_time - current_time;
        x += vx * time_segment;
        y += vy * time_segment;

        current_time = turn_time;

        if (direction == "left")
        {
            long long temp_vx = vx;
            vx = -vy;
            vy = temp_vx;
        }
        else
        {
            long long temp_vx = vx;
            vx = vy;
            vy = -temp_vx;
        }
    }

    long long remaining_time = T - current_time;
    x += vx * remaining_time;
    y += vy * remaining_time;

    cout << x << " " << y << endl;

    return 0;
}