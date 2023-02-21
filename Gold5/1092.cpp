/**
프로그램명 : 1092.cpp
설명 : 배
작성일시 : 2023.02.19
작성자 : abbiddo
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int limit[50];
vector<int> box;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		cin >> n;
	for (int i = 0; i < n; i++) cin >> limit[i];

	int m;	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;	cin >> a;
		box.push_back(a);
	}

	// 정렬
	sort(limit, limit + n);
	sort(box.begin(), box.end());

	// 화물의 최대 무게가 크레인의 무게 제한보다 무거우면 종료
	if (box[m - 1] > limit[n - 1]) {
		cout << -1;
		return 0;
	}

	// 화물이 남아 있으면 반복
	int cnt = 0;
	while (box.size()) {
		int i = box.size() - 1;
		cnt++;
		// 무게 제한이 큰 크레인부터 싣기
		for (int j = n - 1; j >= 0; j--) {
			for (i; i >= 0; i--) {
				if (box[i] <= limit[j]) {
					box.erase(box.begin() + i);
					i--;
					break;
				}
			}
		}
	}
	cout << cnt;
}

/**
실행 결과
2
19 20
7
14 12 16 19 16 1 5
-----
4
**/
