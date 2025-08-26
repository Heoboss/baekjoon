#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int* p, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (*(p + j) < *(p + j - 1)) {
				int tmp = *(p + j);
				*(p + j) = *(p + j - 1);
				*(p + j - 1) = tmp;
			}
		}
	}
}
void print_arr(int* p, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", *(p + i));
	}
}
int main() {
	int size = 0;
	int arr[1000];
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	// 오름 차순 정렬
	bubble_sort(arr,size);
	print_arr(arr, size);
	return 0;
}