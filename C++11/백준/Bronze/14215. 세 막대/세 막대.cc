#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sides(3);
    cin >> sides[0] >> sides[1] >> sides[2];

    // 세 변의 길이를 오름차순으로 정렬
    sort(sides.begin(), sides.end());

    int a = sides[0];
    int b = sides[1];
    int c = sides[2];

    // Case 2: 가장 긴 변이 나머지 두 변의 합보다 크거나 같은 경우
    if (c >= a + b) {
        // 가장 긴 변의 길이를 'a + b - 1'로 줄여야 함
        cout << a + b + (a + b - 1) << endl;
    }
    // Case 1: 이미 삼각형을 만들 수 있는 경우
    else {
        cout << a + b + c << endl;
    }

    return 0;
}