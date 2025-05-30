#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string music;
    getline(cin, music);

    int cntA = 0, cntC = 0;
    char note = music[0];
    if (note == 'A' || note == 'D' || note == 'E')
        cntA++;
    else if (note == 'C' || note == 'F' || note == 'G')
        cntC++;

    for (int i = 1; i < (int)music.size(); i++)
    {
        if (music[i] == '|' && i + 1 < (int)music.size())
        {
            char n = music[i + 1];
            if (n == 'A' || n == 'D' || n == 'E')
                cntA++;
            else if (n == 'C' || n == 'F' || n == 'G')
                cntC++;
        }
    }

    if (cntA > cntC)
    {
        cout << "A-minor";
    }
    else if (cntC > cntA)
    {
        cout << "C-major";
    }
    else
    {
        char last = music.back();
        if (last == 'A' || last == 'D' || last == 'E')
            cout << "A-minor";
        else
            cout << "C-major";
    }

    return 0;
}
