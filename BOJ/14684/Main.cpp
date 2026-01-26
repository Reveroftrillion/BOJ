#include <iostream>
#include <vector>
using namespace std;

bool is_arith_seq(const vector<int>& d) {
    if (d.size() <= 2) return true;
    int diff = d[1] - d[0];
    for (int i = 2; i < (int)d.size(); i++)
        if (d[i] - d[i - 1] != diff)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D;
    cin >> D;

    vector<int> good(720, 0);
    int cnt = 0;

    for (int t = 0; t < 720; t++) {
        int hour = 12 + t / 60;
        int minute = t % 60;
        if (hour > 12) hour -= 12;

        vector<int> digits;

        if (hour >= 10) {
            digits.push_back(hour / 10);
            digits.push_back(hour % 10);
        } else {
            digits.push_back(hour);
        }

        digits.push_back(minute / 10);
        digits.push_back(minute % 10);

        if (is_arith_seq(digits)) {
            good[t] = 1;
            cnt++;
        }
    }

    long long full = D / 720;
    long long rem = D % 720;

    long long ans = cnt * full;
    for (int i = 0; i <= rem; i++)
        ans += good[i];

    cout << ans << '\n';
}
