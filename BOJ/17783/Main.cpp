#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    
    if (n % 2 == 1) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n1\n";
    }
    return 0;
}
