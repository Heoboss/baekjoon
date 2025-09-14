#include <iostream>

int main() {
    // C++ 입출력 속도 향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B;
    
    // 세로 길이 A와 가로 길이 B를 입력받음
    std::cin >> A >> B;
    
    // 넓이(A * B)를 계산하여 출력
    std::cout << A * B << std::endl;
    
    return 0;
}