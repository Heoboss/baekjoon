#include <iostream>
#include <algorithm> // sort 함수를 사용하기 위해
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        // 세 변의 길이를 정렬하여 가장 긴 변을 찾기 쉽게 함
        vector<int> sides = {a, b, c};
        sort(sides.begin(), sides.end());

        // 1. 삼각형 결정조건 확인
        // 가장 긴 변(sides[2])이 나머지 두 변의 합보다 크거나 같으면 삼각형이 아님
        if (sides[2] >= sides[0] + sides[1]) {
            cout << "Invalid\n";
        }
        // 2. 종류 판별
        else if (sides[0] == sides[1] && sides[1] == sides[2]) {
            cout << "Equilateral\n";
        }
        else if (sides[0] == sides[1] || sides[1] == sides[2]) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}