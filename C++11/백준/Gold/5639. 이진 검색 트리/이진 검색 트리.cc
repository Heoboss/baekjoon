#include <iostream>
#include <vector>
#include <climits> // INT_MIN, INT_MAX를 사용하기 위해

using namespace std;

vector<int> preorder;
int preorder_index = 0;

/**
 * @param min_val 현재 서브트리에서 허용되는 최솟값
 * @param max_val 현재 서브트리에서 허용되는 최댓값
 */
void postorder(int min_val, int max_val) {
    // 1. 배열의 끝에 도달했으면 종료
    if (preorder_index == preorder.size()) {
        return;
    }

    // 2. 현재 노드 값을 가져옴
    int root_val = preorder[preorder_index];

    // 3. 현재 노드가 허용된 범위를 벗어나면 이 서브트리에 속하지 않음
    if (root_val < min_val || root_val > max_val) {
        return;
    }

    // 4. 현재 노드를 루트로 확정하고, 다음 노드로 인덱스 이동
    preorder_index++;

    // 5. 왼쪽 서브트리 탐색 (Root보다 작은 값들)
    postorder(min_val, root_val);

    // 6. 오른쪽 서브트리 탐색 (Root보다 큰 값들)
    postorder(root_val, max_val);

    // 7. Left, Right가 모두 끝난 후 Root 출력
    cout << root_val << "\n";
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    // 입력의 끝(EOF)까지 모든 숫자를 vector에 저장
    while (cin >> num) {
        preorder.push_back(num);
    }

    // 전체 트리에 대해 재귀 함수 호출 (초기 범위는 정수 전체)
    postorder(INT_MIN, INT_MAX);

    return 0;
}