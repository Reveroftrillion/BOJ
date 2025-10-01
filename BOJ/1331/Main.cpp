#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool visited[6][6] = {false};
    string str;

    bool okay = true;
    int startR = -1, startC = -1;
    int prevR = -1, prevC = -1;

    for (int k = 0; k < 36; k++)
    {
        if (!(cin >> str))
        {
            cout << "Invalid\n";
            return 0;
        }

        char row = str[0];
        char col = str[1];
        int rowNum = row - 'A';
        int colNum = col - '1';

        if (okay && visited[rowNum][colNum])
        {
            okay = false;
        }
        if (okay)
            visited[rowNum][colNum] = true;

        if (okay && k > 0)
        {
            int dr = abs(rowNum - prevR);
            int dc = abs(colNum - prevC);
            if (!((dr == 1 && dc == 2) || (dr == 2 && dc == 1)))
            {
                okay = false;
            }
        }

        if (k == 0)
        {
            startR = rowNum;
            startC = colNum;
        }

        prevR = rowNum;
        prevC = colNum;
    }

    if (okay)
    {
        int dr = abs(prevR - startR);
        int dc = abs(prevC - startC);
        if (!((dr == 1 && dc == 2) || (dr == 2 && dc == 1)))
        {
            okay = false;
        }
    }

    if (okay)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (!visited[i][j])
                {
                    okay = false;
                    break;
                }
            }
            if (!okay)
                break;
        }
    }

    if (okay)
        cout << "Valid\n";
    else
        cout << "Invalid\n";
    return 0;
}
