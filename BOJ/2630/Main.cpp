#include <iostream>
using namespace std;

int paper[128][128];
int white = 0, blue = 0;

void colored_paper(int x, int y, int size)
{
    int color = paper[x][y];
    bool is_same = true;

    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (paper[i][j] != color)
            {
                is_same = false;
                break;
            }
        }
        if (!is_same)
            break;
    }

    if (is_same)
    {
        if (color == 0)
            white++;
        else
            blue++;
    }
    else
    {
        int half = size / 2;
        // 1사분면
        colored_paper(x, y, half);
        // 2사분면
        colored_paper(x, y + half, half);
        // 3사분면
        colored_paper(x + half, y, half);
        // 4사분면
        colored_paper(x + half, y + half, half);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> paper[i][j];

    colored_paper(0, 0, n);

    cout << white << '\n'
         << blue << '\n';
    return 0;
}