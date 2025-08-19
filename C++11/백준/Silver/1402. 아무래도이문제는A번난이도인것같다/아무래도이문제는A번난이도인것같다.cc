#include <iostream>

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        long long A, B; // A, B 값은 사용하지 않지만 입력 형식에 맞게 읽어줍니다.
        std::cin >> A >> B;
        std::cout << "yes\n";
    }

    return 0;
}