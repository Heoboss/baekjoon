#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n;
bool check[1000010];
vector<int> vec;
 
// 사람들이 원하는 용량이 0 ~ 1,000,000 이고,
// n의 최댓값이 1000이므로 
// 모든 경우의 수를 확인하더라도
// 1,000,000,000. 즉 10억이다.
// 따라서 이 문제는 일일이 모두 확인하더라도 시간초과가가 나지 않은다.
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
        check[temp] = 1;
    }
 
    
    int ans = 0;
 
    // 사람들이 요구했던 모든 용량 중 하나를 골라
    // 제외한 후 최대 길이를 측정한다.
    for (int i = 0; i < 1000001; i++)
    {    // 특정 용량을 원하는 사람을 제외한다.
        if (check[i])
        {
            int m = vec[0];
            int m_cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (vec[j] == i) continue;
                if (m == vec[j]) m_cnt++;
                else if (m != vec[j])
                {
                    m = vec[j];
                    m_cnt = 1;
                }
                else if (j == n - 1)
                {
                    m_cnt++;
                }
                ans = max(ans, m_cnt);
            }
        }
    }
 
    cout << ans;
 
    return 0;
}