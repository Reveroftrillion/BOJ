#include <iostream>
using namespace std;

int main()
{
    int N, day;
    cin >> N >> day;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((N % 4 == 0 && N % 100 != 0) || (N % 400 == 0))
    {
        days[1] = 29;
    }

    int start = day - 1; // 0=일요일, …, 6=토요일
    int answer = 0;

    for (int m = 0; m < 12; ++m)
    {
        int L = days[m];
        for (int w = 0; w < 7; ++w)
        {
            int offset = (w - start + 7) % 7;
            if (offset >= L)
                continue;

            int cnt = (L - offset + 6) / 7;

            if (cnt == 5)
                answer++;
        }

        start = (start + L) % 7;
    }

    cout << answer;
    return 0;
}