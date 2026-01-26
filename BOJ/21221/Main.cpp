#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> b(n, string(m, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                b[i][j] = '#';
                b[i + 1][j] = '#';
                b[i][j + 1] = '#';
                b[i + 1][j + 1] = '#';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << '\n';
    }

    return 0;
}
