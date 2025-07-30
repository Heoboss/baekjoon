#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문자열 정렬 기준: 길이 -> 사전 순
bool compare(const string &a, const string &b) {
    if (a.length() == b.length()) return a < b; // 길이가 같으면 사전순 정렬
    return a.length() < b.length(); // 길이가 짧은 순으로 정렬
}

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), compare); // 정렬
    words.erase(unique(words.begin(), words.end()), words.end()); // 중복 제거

    for (const string &word : words) {
        cout << word << '\n';
    }

    return 0;
}
