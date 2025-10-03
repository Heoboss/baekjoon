#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // sort 함수를 사용하기 위해
#include <functional> // greater<>를 사용하기 위해

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    cin >> N;

    // 문자열의 문자들을 내림차순으로 정렬
    sort(N.begin(), N.end(), greater<char>());

    cout << N << endl;

    return 0;
}