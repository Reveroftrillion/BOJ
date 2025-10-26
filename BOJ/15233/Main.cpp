#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve()
{
    int A, B, G;

    if (!(cin >> A >> B >> G))
        return;

    set<string> team_A_roster;
    for (int i = 0; i < A; ++i)
    {
        string player_name;
        cin >> player_name;
        team_A_roster.insert(player_name);
    }

    set<string> team_B_roster;
    for (int i = 0; i < B; ++i)
    {
        string player_name;
        cin >> player_name;
        team_B_roster.insert(player_name);
    }

    int score_A = 0;
    int score_B = 0;

    for (int i = 0; i < G; ++i)
    {
        string scorer_name;
        cin >> scorer_name;

        if (team_A_roster.count(scorer_name))
        {
            score_A++;
        }
        else if (team_B_roster.count(scorer_name))
        {
            score_B++;
        }
    }

    if (score_A > score_B)
    {
        cout << "A" << endl;
    }
    else if (score_B > score_A)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "TIE" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}