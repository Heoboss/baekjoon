#include <iostream>
using namespace std;

int N, K;

int selection_sort(int A[]);

int selection_sort(int A[]) {
	int count = 0; // 교환 횟수

	// A[1..N]을 오름차순 정렬한다.
	for (int i = N - 1; i > 0; i--) {
		int big = 0;

		// A[]중 가장 큰 수를 찾는다
		for (int j = 0; j <= i; j++)
			if (A[j] > A[big]) big = j;

		// last와 big이 서로 다르면 A[last]와 A[big]을 교환
		if (big != i) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;

			count++;
		}

		// K 번째 교환
		if (count == K) {
			for (int j = 0; j < N; j++) // 출력
				printf("%d ", A[j]);

			return 0;
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &N, &K);

	int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	// 출력
	if (selection_sort(A) == -1)
		printf("-1\n");

	delete[] A;

	return 0;
}