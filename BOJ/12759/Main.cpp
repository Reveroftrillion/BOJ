#include <bits/stdc++.h>
using namespace std;

bool win(const vector<string> &b, char p)
{
    for (int i = 0; i < 3; ++i)
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p)
            return true;
    for (int j = 0; j < 3; ++j)
        if (b[0][j] == p && b[1][j] == p && b[2][j] == p)
            return true;
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p)
        return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int starter;
    if (!(cin >> starter))
        return 0;

    vector<string> board(3, string(3, '.'));
    int current = starter;
    for (int move = 0; move < 9; ++move)
    {
        int r, c;
        cin >> r >> c;
        char symbol = (current == 1 ? 'O' : 'X');
        board[r - 1][c - 1] = symbol;

        if (win(board, symbol))
        {
            cout << current << '\n';
            return 0;
        }

        current = 3 - current;
    }

    cout << 0 << '\n';
    return 0;
}
