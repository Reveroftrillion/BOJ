#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, X;
    std::cin >> N >> M >> X;

    std::vector<int> H(M);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> H[i];
    }

    std::vector<std::vector<char>> grid(N, std::vector<char>(M, '.'));

    // 산(#) 채우기
    for (int j = 0; j < M; ++j)
    {
        for (int i = N - 1; i >= N - H[j]; --i)
        {
            grid[i][j] = '#';
        }
    }

    int highway_row = N - X;

    for (int j = 0; j < M; ++j)
    {
        if (H[j] >= X)
        {
            grid[highway_row][j] = '*';
        }
        else
        {
            grid[highway_row][j] = '-';
            if ((j + 1) % 3 == 0)
            {
                for (int k = highway_row + 1; k <= N - H[j] - 1; ++k)
                {
                    grid[k][j] = '|';
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
