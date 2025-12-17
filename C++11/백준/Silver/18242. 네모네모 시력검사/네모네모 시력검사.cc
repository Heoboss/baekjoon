#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M)); // map[N][M] N이 height, M이 width

    int minX, minY, maxX, maxY;

    bool isFirstSharp = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '#' && isFirstSharp == false)
            {
                minY = i;
                minX = j;
                isFirstSharp = true;
            }
            else if (map[i][j] == '#')
            {
                maxY = i;
                maxX = j;
            }
        }
    }

    const int width = maxX - minX;
    const int height = maxY - minY;

    if (map[minY][minX + width / 2] == '.')
        cout << "UP" << '\n';
    if (map[maxY][minX + width / 2] == '.')
        cout << "DOWN" << '\n';
    if (map[minY + height / 2][minX] == '.')
        cout << "LEFT" << '\n';
    if (map[minY + height / 2][maxX] == '.')
        cout << "RIGHT" << '\n';

    return 0;
}