#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using pdi = pair<double, int>;

int N;
vector<pdi> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    v.reserve(N);

    for (int i = 1; i <= N; ++i)
    {
        double X, Y, V;
        cin >> X >> Y >> V;

        v.push_back({sqrt((X * X + Y * Y)) / V, i});
    }

    sort(v.begin(), v.end());

    for (const pdi &p : v)
    {
        cout << p.second << "\n";
    }
    return 0;
}