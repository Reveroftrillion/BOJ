#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

void eratosthenes() // 에라토스테네스의 채 구현
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    eratosthenes();

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        bool found = false;
        for (int a = 3; a <= n / 2; a++)
        {
            if (is_prime[a] && is_prime[n - a])
            {
                cout << n << " = " << a << " + " << n - a << '\n';
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
