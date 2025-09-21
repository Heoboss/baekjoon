#include <iostream>

int main() {
    // C++ 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n; // N이 10^9까지 가능하므로 long long 사용
    std::cin >> n;
    
    // 둘레 길이는 4 * n
    std::cout << 4 * n << std::endl;
    
    return 0;
}