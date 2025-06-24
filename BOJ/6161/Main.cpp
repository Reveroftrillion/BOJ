#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int songCount, playCount;
    cin >> songCount >> playCount;
    vector<int> ratings(songCount + 1); // 1-based indexing

    for (int songIndex = 1; songIndex <= songCount; ++songIndex)
        cin >> ratings[songIndex];

    for (int round = 0; round < playCount; ++round)
    {
        // 1) 최고 평점 노래 찾기
        int selectedSong = 1;
        for (int songIndex = 2; songIndex <= songCount; ++songIndex)
        {
            if (ratings[songIndex] > ratings[selectedSong])
                selectedSong = songIndex;
        }

        cout << selectedSong << '\n';

        int originalRating = ratings[selectedSong];
        ratings[selectedSong] = 0;

        int distributeEvenly = originalRating / (songCount - 1);
        int extraPoints = originalRating % (songCount - 1);

        for (int songIndex = 1; songIndex <= songCount; ++songIndex)
        {
            if (songIndex == selectedSong)
                continue;

            ratings[songIndex] += distributeEvenly;

            if (extraPoints > 0)
            {
                ratings[songIndex] += 1;
                --extraPoints;
            }
        }
    }

    return 0;
}