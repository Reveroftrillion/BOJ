#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int check_candies(const vector<string> &board)
{
    int n = board.size();
    int max_count = 1;

    for (int i = 0; i < n; ++i)
    {
        int count = 1;
        for (int j = 1; j < n; ++j)
        {
            if (board[i][j] == board[i][j - 1])
                count++;
            else
            {
                max_count = max(max_count, count);
                count = 1;
            }
        }
        max_count = max(max_count, count);

        count = 1;
        for (int j = 1; j < n; ++j)
        {
            if (board[j][i] == board[j - 1][i])
            {
                count++;
            }
            else
            {
                max_count = max(max_count, count);
                count = 1;
            }
        }
        max_count = max(max_count, count);
    }
    return max_count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> board(n);
    int max_candies = 0;

    for (int i = 0; i < n; ++i)
        cin >> board[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j + 1 < n)
            {
                swap(board[i][j], board[i][j + 1]);
                max_candies = max(max_candies, check_candies(board));
                swap(board[i][j], board[i][j + 1]);
            }

            if (i + 1 < n)
            {
                swap(board[i][j], board[i + 1][j]);
                max_candies = max(max_candies, check_candies(board));
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    cout << max_candies << "\n";

    return 0;
}