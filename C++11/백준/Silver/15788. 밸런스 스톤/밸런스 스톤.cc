#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N, y, x;
vector<vector<ll>> map;
ll s, sum;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    map = vector<vector<ll>>(N, vector<ll>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if (!map[i][j])
            {
                y = i;
                x = j;
            }
        }
    }
}
void caclM()
{
    // 합 구하기
    for (int i = 0; i < 2; ++i)
    {
        s = 0;
        for (int j = 0; j < N; ++j)
        {
            s += map[i][j];
        }
        sum = max(s, sum);
    }

    // M의 줄 합 구해서 빠진 값 채우기
    s = 0;
    for (int i = 0; i < N; ++i)
    {
        s += map[y][i];
    }

    map[y][x] = sum - s;
}
bool checkLeftCross() // 좌측 위 대각선
{
    s = 0;
    for (int i = 0; i < N; ++i)
    {
        s += map[i][i];
    }
    return s == sum;
}
bool checkRightCross() // 우측 위 대각선
{
    s = 0;
    for (int i = 0; i < N; ++i)
    {
        s += map[N - 1 - i][i];
    }
    return s == sum;
}
bool checkRow()
{
    for (int i = 0; i < N; ++i)
    {
        s = 0;
        for (int j = 0; j < N; ++j)
        {
            s += map[i][j];
        }
        if (s != sum)
        {
            return false;
        }
    }
    return true;
}
bool checkCol()
{
    for (int i = 0; i < N; ++i)
    {
        s = 0;
        for (int j = 0; j < N; ++j)
        {
            s += map[j][i];
        }
        if (s != sum)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    input();
    caclM();

    if (checkLeftCross() && checkRightCross() && checkRow() && checkCol())
    {
        cout << map[y][x];
        return 0;
    }

    cout << -1;
    return 0;
}