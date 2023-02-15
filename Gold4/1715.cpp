/**
프로그램명 : 1715.cpp
설명 : 카드 정렬하기
작성일시 : 2023.02.15
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

// 오름차순 우선순위 큐
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;	cin >> a;
		pq.push(a);
	}

	// 큐의 사이즈가 1이면, 카드가 한 묶음이면 종료
	while (pq.size() > 1) {
		int one = pq.top();	pq.pop();
		int two = pq.top();	pq.pop();
		pq.push(one + two);
		sum += one + two;
	}

	cout << sum;
}

/**
실행 결과
4
20
30
40
45
-----
270
**/
