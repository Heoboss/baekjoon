#include <iostream>
using namespace std;

int N;
int dp[100000][6];
int AB[100000][2];
int maxCount;
int grade;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> AB[i][0] >> AB[i][1];
    }

    dp[0][AB[0][0]] = 1;
    dp[0][AB[0][1]] = 1;

    maxCount = 1;
    grade = min(AB[0][0], AB[0][1]);

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            int ab = AB[i][j];
            int &value = dp[i][ab];
            value = dp[i - 1][ab] + 1;

            if (value > maxCount)
            {
                maxCount = value;
                grade = ab;
            }
            else if (value == maxCount)
            {
                grade = min(grade, ab);
            }
        }
    }

    cout << maxCount << " " << grade;
    return 0;
}