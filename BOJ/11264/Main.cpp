#include <bits/stdc++.h>
using namespace std;

int step(double a) {
    return (a >= 0) ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string type;
        double W1, W2, B;
        cin >> type >> W1 >> W2 >> B;

        bool ok = true;

        for (int x1 = 0; x1 <= 1; x1++) {
            for (int x2 = 0; x2 <= 1; x2++) {
                double A = x1 * W1 + x2 * W2 + B;
                int out = step(A);

                int expected;
                if (type == "AND")
                    expected = (x1 & x2);
                else // OR
                    expected = (x1 | x2);

                if (out != expected) {
                    ok = false;
                }
            }
        }

        cout << (ok ? "true" : "false") << '\n';
    }
}
