#include <iostream>
#include <iomanip> // setw, setfill을 사용하기 위해 필요합니다.

int main() {
    // 입출력 속도 향상을 위한 설정 (문제의 입력이 적어 필수는 아님)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double N, M; // 정수 나눗셈의 오차를 피하기 위해 double로 입력받습니다.
    std::cin >> N >> M;

    // 국방시계의 총 시간(분) = 24시간 * 60분
    const int total_clock_minutes = 24 * 60;

    // 복무 비율에 따라 경과된 시간을 분 단위로 계산합니다.
    double elapsed_minutes_double = (M / N) * total_clock_minutes;

    // 문제의 '버림' 조건에 따라 소수점 이하를 버립니다.
    int total_elapsed_minutes = static_cast<int>(elapsed_minutes_double);

    // 총 경과 시간을 '시'와 '분'으로 변환합니다.
    int hours = total_elapsed_minutes / 60;
    int minutes = total_elapsed_minutes % 60;

    // HH:MM 형식에 맞춰 출력합니다.
    // std::setw(2): 출력 너비를 2칸으로 설정
    // std::setfill('0'): 빈칸을 '0'으로 채움
    std::cout << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << std::endl;

    return 0;
}