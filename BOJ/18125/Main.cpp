#include <iostream>
using namespace std;

int R, C;
int arr[100][100];
bool chk = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> R;

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
            cin >> arr[r][c];
    }

    for (int c = 0; c < C; c++)
    {
        for (int r = R - 1; r > -1; r--)
        {
            int x;
            cin >> x;
            if (arr[r][c] != x)
                chk = 0;
        }
    }

    if (chk)
    {
        cout << "|>___/|        /}\n"
             << "| O < |       / }\n"
             << "(==0==)------/ }\n"
             << "| ^  _____    |\n"
             << "|_|_/     ||__|";
    }
    else
    {
        cout << "|>___/|     /}\n"
             << "| O O |    / }\n"
             << "( =0= )\"\"\"\"  \\\n"
             << "| ^  ____    |\n"
             << "|_|_/    ||__|";
    }
}