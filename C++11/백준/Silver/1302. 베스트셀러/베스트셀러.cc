#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N;
	map <string, int> book;
	string input;
	int max_sales_rate;
	string best_seller;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;

		// 1. 입력받은 책과 동일한 책이 없는 경우
		if (book.find(input) == book.end()) {
			book.insert({ input, 1 });
		}
		// 2. 입력받은 책과 동일한 책이 있는 경우
		else {
			book[input]++;
		}
	}

	// 1. 가장 많이 팔린 책의 판매량 찾기
	max_sales_rate = 0;
	for (auto i = book.begin(); i != book.end(); i++) {
		max_sales_rate = max(max_sales_rate, i->second);
	}

	// 2. 가장 많은 판매량을 가진 책의 이름을 찾기
	// map은 key값을 기준으로 자동 정렬. 즉, 책 이름 순으로 정렬되어있음.
	// 가장 많이 팔린 책이 여러개여도 사전순으로 앞서는 것으로 출력됨.
	for (auto i = book.begin(); i != book.end(); i++) {
		if (max_sales_rate == i->second) {
			best_seller = i->first;
			break;
		}
	}

	cout << best_seller;

	return 0;
}
