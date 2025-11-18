#include <iostream>
#include <cmath>

#define MAX 295246           // 파생되는 숫자의 최대값은 295245이기에  

int visited[MAX] = {0,};     // 전부 0으로 초기화
int P;                       

void dfs(int x) {            // dfs 함수 
    
    if (visited[x] == 2) return ;       // 반복순열의 시작이라면 탐색 종료

    visited[x] += 1;                    

    int result = 0;                      
    while (x)
    {
        result += (int)pow( (x%10),P );
        x /= 10;
    }

    dfs(result);
}

int main(void) {
    int A;
    std::cin >> A >> P;

    dfs(A);
    int result = 0;
    
    for (int i = 0; i < MAX; i++) {
        if (visited[i] == 1) result++;
    }
    
    std::cout << result << "\n";

    return 0;
}