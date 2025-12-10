#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long ans = floor(2.0 * abs(b - a) / b);
    cout << ans << '\n';
}